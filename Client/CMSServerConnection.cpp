#include "CMSServerConnection.h"
#include "../Util/Random/Sequential.h"
#include "../Util/Thread/ThreadLogger.h"
#include "../Util/Thread/Condition.h"

CMSServerConnection::CMSServerConnection(const std::string& ip, int p):
            conn(Connection::open(ip, p)) {
    
    closed = false;
    
    //connection
    connectionActive = true;
    
    //clients
    clientsMapLock = Mutex::createMutex();
    
    //writer
    writeLock = Mutex::createMutex();
    
    //Waiter
    waitersLock = Mutex::createMutex();
    
    //reader
    readerThread  = Thread<CMSServerConnection, int>::createThread(this, &CMSServerConnection::processIncomingMessages);
    readerThread->start(0);
    
    //resend
    sentDataLock = Mutex::createMutex();
    resendThread = Thread<CMSServerConnection, int>::createThread(this, &CMSServerConnection::resendProcess);
    resendThread->start(0);
}

CMSServerConnection::~CMSServerConnection(){
    if (!closed)
        close();
}


void CMSServerConnection::close(){
    //destroy connection    
    if (connectionActive){
        conn.close();
        connectionActive = false;
    }
    
    //destroy waiters
    for (std::map<UniqueID, ACKWaiter>::iterator it =waiters.begin();
                    it != waiters.end(); it++) {
        delete it->second.condition;
        delete it->second.mutex;
    }
    delete waitersLock;
    
    //destroy Clients
    for (std::map<UniqueID, CMSClient*>::iterator it=clients.begin();
                    it != clients.begin(); it++) {
        delete it->second;
    }
    delete clientsMapLock;
    
    //destroy reader
    readerThreadActive = false;
    readerThread->kill();
    readerThread->join();
    delete readerThread;
    
    //destroy resender
    resendThreadActive = false;
    resendThread->kill();
    resendThread->join();
    delete resendThread;
    delete sentDataLock;
    
    //destroy writer
    delete writeLock;
    
    closed = true;
}

bool CMSServerConnection::write_(GenericCMSMessage& msg,  bool wait) {
    std::string msgID = msg.getStandardHeader("message-id");
    
    writeLock->acquire();
    if (conn.write(msg.str()) > 0) {
        Time t;
        CMSMessageSendData cmsd = {msg, t, t, msgID};
        sentDataLock->acquire();
        sentData.push_back(cmsd);
        sentDataLock->release();
        
        writeLock->release();
        return true;
    } else {
        conn.closeWriting();
        writeLock->release();
        return false;
    }    
}


UniqueID CMSServerConnection::write(GenericCMSMessage& msg) {
    if (!conn.writable())
        return "";
    UniqueID id = Sequential::next();
    msg.updateStandardHeader("message-id", id);
    
    if (write_(msg, false))
        return id;
    return "";
}

bool CMSServerConnection::writeWithAck(GenericCMSMessage& msg) {
    if (!conn.writable())
        return false;
    
    UniqueID id = Sequential::next();
    msg.updateStandardHeader("message-id", id);
    
    Mutex* m = Mutex::createMutex();
    Condition* c = Condition::createCondition(m);
    ACKWaiter waiter = {m, c};
    waiters[id] = waiter;
    
    bool result = write_(msg, true);
    if (result){
        c->wait();
    }
    delete c;
    delete m;
    waiters.erase(id);
    
    return result;
}


void CMSServerConnection::resendProcess(int) {
    resendThreadActive = true;
    
    while (resendThreadActive && conn.writable()) {
        break;
    }
    
    resendThreadActive = false;
}

void CMSServerConnection::processIncomingMessages(int){
    readerThreadActive = true;
    tlog("Incoming message processor started!");
    
    while (conn.readable() && readerThreadActive){
        GenericCMSMessage out;
        if (!GenericCMSMessage::parse(conn, out)){
            break;
        }
        std::string messageID = out.getStandardHeader("message-id");
        std::string receiverID = out.getStandardHeader("receiver-id");
        CMSClient* receiver = clients[receiverID];
        
        if (!out.isForward()) { //ACKNOWLEDGEMENT
            std::string ackForMsgID = out.getStandardHeader("acknowlegdement-for-message-id");
            bool topicOrQueue = out.category() == GenericCMSMessage::Queue ||
                    out.category() == GenericCMSMessage::Topic;
            
            waitersLock->acquire();
            std::map<UniqueID, ACKWaiter>::iterator it = waiters.find(ackForMsgID);
            bool waiterFound = it != waiters.end();
            waitersLock->release();
            
            if (waiterFound) {
                waiters[ackForMsgID].condition->signal();
            } else if (topicOrQueue) {
                //Acknowledgement for Queue/Topic Message!!
                if (receiver)
                    receiver->onAcknowledgement(messageID, out);
                
                //erase from 0 to index of current ACK!
                sentDataLock->acquire();
                std::vector<CMSMessageSendData>::iterator it;
                bool found = false;
                for (it = sentData.begin(); it != sentData.end(); it++) {
                    if (it->id == ackForMsgID){
                        it ++;
                        found = true;
                        break;
                    }
                }
                
                if (!found)
                    tlog("Stray Ack received!");
                else
                    sentData.erase(sentData.begin(), it);
                
                sentDataLock->release();
            }
        } else {
            if (receiver)
                receiver->onMessage(out);
            else
                tlog("FATAL LOSS: NO receiver registered!\n"<<out.str());
        }
    }
    tlog("Incoming message processor shutdown");
}

bool CMSServerConnection::doRegister(CMSClient* receiver, bool reg) {
    CMSHeaderSet chs, custom;
    chs["receiver-id"] = receiver->id();
    chs["direction"] = "forward";
    chs["category"] = reg?
        GenericCMSMessage::CMSMessageTypeToStr(GenericCMSMessage::Register):
        GenericCMSMessage::CMSMessageTypeToStr(GenericCMSMessage::UnRegister);
    chs["has-custom-headers"] = "false";
    GenericCMSMessage msg(chs, custom, "");
    
    if (writeWithAck(msg)) {
        if (reg)
            tlog("Registered!!");
        else
            tlog("Unregistered!!");
        return true;
    } else {
        tlog("Error while writing with ACK!");
        return false;
    }
}

