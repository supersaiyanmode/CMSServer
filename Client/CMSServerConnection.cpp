#include "CMSServerConnection.h"
#include "../Util/Random/Sequential.h"
#include "../Util/Thread/ThreadLogger.h"
#include "../Util/Thread/Condition.h"

CMSServerConnection::CMSServerConnection(const std::string& ip, int p):
            conn(Connection::open(ip, p)) {
    connectionActive = true;
    
    readerThread  = Thread<CMSServerConnection, int>::createThread(this, &CMSServerConnection::processIncomingMessages);
    writeLock = Mutex::createMutex();
    pendingAcknowledgementsMapLock = Mutex::createMutex();
    clientsMapLock = Mutex::createMutex();
    
    readerThread->start(0);
}

CMSServerConnection::~CMSServerConnection(){
    for (std::map<UniqueID, Condition*>::iterator it = pendingRegistrationsConditions.begin();
                    it != pendingRegistrationsConditions.end(); it++) {
        delete it->second;
    }
    for (std::map<UniqueID, Mutex*>::iterator it = pendingRegistrationsMutexes.begin();
                    it != pendingRegistrationsMutexes.end(); it++) {
        delete it->second;
    }
    
    close(); //connection close!
    readerThreadActive = false;
    readerThread->kill();
    readerThread->join();
    delete readerThread;
    delete writeLock;
    delete clientsMapLock;
}



void CMSServerConnection::close(){
    if (connectionActive){
        conn.close();
        connectionActive = false;
    }
}

UniqueID CMSServerConnection::write(GenericCMSMessage& msg) {
    if (!conn.writable())
        return "";
    writeLock->acquire();
    UniqueID id = Sequential::next();
    msg.updateStandardHeader("message-id", id);
    //In case its register/unregister
    if (msg.category() == GenericCMSMessage::Register ||
                msg.category() == GenericCMSMessage::UnRegister){
        Mutex* m = Mutex::createMutex();
        pendingRegistrationsMutexes[id] = m;
        pendingRegistrationsConditions[id] = Condition::createCondition(m);
    }
    
    if (conn.write(msg.str()) > 0) {
        pendingAcknowledgementsMapLock->acquire();
        pendingAcknowledgements[id] = msg;
        pendingAcknowledgementsMapLock->release();
    } else {
        id = "";
        conn.closeWriting();
        
        //delete our mutex and condition
        delete pendingRegistrationsConditions[id];
        delete pendingRegistrationsMutexes[id];
    
        pendingRegistrationsConditions.erase(id);
        pendingRegistrationsMutexes.erase(id);
    }
    
    writeLock->release();
    return id;
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
            if (out.category() == GenericCMSMessage::Register || 
                    out.category() == GenericCMSMessage::UnRegister) {
                pendingAcknowledgements[messageID] = out;
                pendingRegistrationsConditions[messageID]->signal();
            } else if (out.category() == GenericCMSMessage::Queue ||
                    out.category() == GenericCMSMessage::Topic) {
                if (receiver)
                    receiver->onAcknowledgement(messageID, out);
                pendingAcknowledgementsMapLock->acquire();
                pendingAcknowledgements.erase(messageID);
                pendingAcknowledgementsMapLock->release();
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
    
    std::string messageID = write(msg);
    pendingRegistrationsConditions[messageID]->wait();
    
    pendingAcknowledgementsMapLock->acquire();
    GenericCMSMessage& ackMsg = pendingAcknowledgements[messageID];
    pendingAcknowledgements.erase(messageID);
    pendingAcknowledgementsMapLock->release();
    
    if (reg)
        tlog("Registered!!\n"<<ackMsg.str());
    else
        tlog("Unregistered!!\n"<<ackMsg.str());
    
    delete pendingRegistrationsConditions[messageID];
    delete pendingRegistrationsMutexes[messageID];

    pendingRegistrationsConditions.erase(messageID);
    pendingRegistrationsMutexes.erase(messageID);
    
    
    return true;
}

