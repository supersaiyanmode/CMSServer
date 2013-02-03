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
    clientsMapRWLock = ReadWriteLock::createReadWriteLock();
    
    //writer
    writeLock = Mutex::createMutex();
    
    //Waiter
    waitersRWLock = ReadWriteLock::createReadWriteLock();
    
    //reader
    readerThread  = Thread<CMSServerConnection, int>::createThread(this, &CMSServerConnection::processIncomingMessages);
    readerThread->start(0);
    
    //resend
    sentDataRWLock = ReadWriteLock::createReadWriteLock();
    resendThread = Thread<CMSServerConnection, int>::createThread(this, &CMSServerConnection::resendProcess);
    resendThread->start(0);
}

CMSServerConnection::~CMSServerConnection(){
    if (!closed)
        close();
    readerThread->join();
    delete readerThread;
    
    resendThread->join();
    
    delete resendThread;
    delete sentDataRWLock;
    
    //destroy writer
    delete writeLock;
}


void CMSServerConnection::close(){
    tlog("Disconnected. Shutting down...");
    //destroy connection    
    if (connectionActive){
        conn.close();
        connectionActive = false;
    }
    
    //Singal ACKWaiter with result=false
    waitersRWLock->lockRead();
    for (std::map<UniqueID, ACKWaiter>::iterator it=waiters.begin(); it!=waiters.end(); it++){
        it->second.result = false;
        it->second.condition->signal();
    }
    //Dont clear the map, not needed. Waiters will erase their own entry by themselves.
    waitersRWLock->unlockRead();
    
    clientsMapRWLock->lockWrite();
    for (std::map<UniqueID, CMSClient*>::iterator it=clients.begin(); it!= clients.end(); it++)
        it->second->onDisconnect();
    clients.clear();
    clientsMapRWLock->unlockWrite();
    
    //destroy reader
    readerThreadActive = false;
    readerThread->kill();
    
    //destroy resender
    resendThreadActive = false;
    resendThread->kill();
    
    closed = true;
    tlog("CMSServer Connection closed!");
}

bool CMSServerConnection::write_(GenericCMSMessage& msg,  bool wait) {
    std::string msgID = msg.getStandardHeader("local-message-id");
    
    writeLock->acquire();
    if (conn.write(msg.str()) > 0) {
        Time t;
        CMSMessageSendData cmsd = {msg, t, t, msgID};
        sentDataRWLock->lockWrite();
        sentData.push_back(cmsd);
        sentDataRWLock->unlockWrite();
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
    msg.updateStandardHeader("local-message-id", id);
    
    if (write_(msg, false))
        return id;
    return "";
}

bool CMSServerConnection::writeWithAck(GenericCMSMessage& msg, GenericCMSMessage& out) {
    if (!conn.writable())
        return false;
    
    UniqueID id = Sequential::next();
    msg.updateStandardHeader("local-message-id", id);
    
    Mutex* m = Mutex::createMutex();
    Condition* c = Condition::createCondition(m);
    ACKWaiter waiter = {false, m, c, GenericCMSMessage()};
    
    //READ WRITE LOCK HERE!!!
    waitersRWLock->lockWrite();
    waiters[id] = waiter;
    waitersRWLock->unlockWrite();
    
    bool result = write_(msg, true);
    if (result){
        c->wait();
    }
    delete c;   //Note: dont double delete using the pointers inside waiter
    delete m;
    
    waitersRWLock->lockWrite();
    ACKWaiter ackWaiterNew = waiters[id];
    waiters.erase(id);
    waitersRWLock->unlockWrite();
    
    if (result && ackWaiterNew.result) //Need to check for ackWaiterNew.result: What is conn is closed while waiter for ACK?
        out = ackWaiterNew.ackMsg;
    
    return result;
}


void CMSServerConnection::resendProcess(int) {
    resendThreadActive = true;
    //TODO: Resend messages to the server if no ACK..
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
            continue; //will break out if !conn.readable()
        }
        std::string messageID = out.getStandardHeader("global-message-id");
        std::string receiverID = out.getStandardHeader("receiver-id");
        CMSClient* receiver;
        
        clientsMapRWLock->lockRead();
        std::map<UniqueID, CMSClient*>::iterator it = clients.find(receiverID);
        if (it == clients.end())
            receiver = NULL;
        else
            receiver = it->second;
        clientsMapRWLock->unlockRead();
        
        if (!out.isForward()) { //ACKNOWLEDGEMENT
            std::string ackForMsgID = out.getStandardHeader("acknowlegdement-for-local-message-id");
            bool topicOrQueue = out.category() == GenericCMSMessage::Queue ||
                    out.category() == GenericCMSMessage::Topic;
            
            waitersRWLock->lockRead();
            std::map<UniqueID, ACKWaiter>::iterator it = waiters.find(ackForMsgID);
            bool waiterFound = it != waiters.end();
            waitersRWLock->unlockRead();

            if (waiterFound) {
                waitersRWLock->lockWrite(); //Bad "upgrade" from read to write, but fine since none else deletes
                waiters[ackForMsgID].result = true;
                waiters[ackForMsgID].ackMsg = out;
                waiters[ackForMsgID].condition->signal();
                waitersRWLock->unlockWrite();
            } else if (topicOrQueue) {
                //Acknowledgement for Queue/Topic Message!!
                if (receiver)
                    receiver->onAcknowledgement(messageID, out);
                
                //erase from 0 to index of current ACK!
                sentDataRWLock->lockWrite();
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
                
                sentDataRWLock->unlockWrite();
            } else {
                tlog("No waiter or Topic/Queue receiver found for ACK message.");
            }
        } else {
            if (receiver)
                receiver->onMessage(out);
            else
                tlog("FATAL LOSS: NO receiver registered!\n"<<out.str());
        }
    }
    close();
}

bool CMSServerConnection::doRegister(CMSClient* receiver, bool reg, GenericCMSMessage& ackMsg) {
    CMSHeaderSet chs, custom;
    chs["receiver-id"] = receiver->id();
    chs["direction"] = "forward";
    chs["category"] = reg?
        GenericCMSMessage::CMSMessageTypeToStr(GenericCMSMessage::Register):
        GenericCMSMessage::CMSMessageTypeToStr(GenericCMSMessage::UnRegister);
    chs["destination"] = receiver->destination();
    chs["has-custom-headers"] = "false";
    GenericCMSMessage msg(chs, custom, "");
    
    return writeWithAck(msg, ackMsg);
}

bool CMSServerConnection::registerClient(CMSClient* receiver) {
    GenericCMSMessage ackMsg;
    if (!doRegister(receiver, true,ackMsg))
        return false;
    if (ackMsg.getStandardHeader("acknowledgement-result") != "SUCCESS"){
        std::string errMsg = ackMsg.getStandardHeader("acknowledgement-error-description");
        tlog("Unable to register: "<<errMsg);
        return false;
    }
    
    //add to clients: std::map<UniqueID, CMSClient*>
    clientsMapRWLock->lockWrite();
    clients[receiver->id()] = receiver;
    clientsMapRWLock->unlockWrite();
    
    return true;
}

bool CMSServerConnection::unregisterClient(CMSClient* receiver) {
    GenericCMSMessage ackMsg;
    if (!doRegister(receiver, false,ackMsg))
        return false;
    if (ackMsg.getStandardHeader("acknowledgement-result") != "SUCCESS"){
        //tlog("Resp: "<<ackMsg.getStandardHeader("acknowledgement"))
        std::string errMsg = ackMsg.getStandardHeader("acknowledgement-error-description");
        tlog("Unable to unregister: "<<errMsg);
        return false;
    }
    
    clientsMapRWLock->lockWrite();
    std::map<UniqueID, CMSClient*>::iterator it = clients.find(receiver->id());
    if (it != clients.end())
        clients.erase(it);
    clientsMapRWLock->unlockWrite();
    return true;
}
