#include "MessageProcessor.h"

MessageProcessor::MessageProcessor() {
	lock = ReadWriteLock::createReadWriteLock();
}

MessageProcessor::~MessageProcessor() {
    delete lock;
}

std::vector<RegistrationData>::iterator MessageProcessor::find(
            ClientEndPoint* cep,
            const std::string& receiverID,
            const std::string& destination,
            int fields){
    std::vector<RegistrationData>::iterator it;
    lock->lockRead();
    for (it=registrations.begin(); it!=registrations.end(); it++){
        if ((fields & 4) && (it->client != cep))
            continue;
        if ((fields & 2) && (it->receiverID != receiverID))
            continue;
        if ((fields & 1) && (it->destination != destination))
            continue;
        lock->unlockRead();
        return it;
    }
    lock->unlockRead();
    return it;
}

bool MessageProcessor::registerReceiver(
            ClientEndPoint* cep,
            const std::string& receiverID,
            const std::string& dest){
    if (find(cep, receiverID, dest, 7) != registrations.end())
        return false;
    RegistrationData rd = {cep, receiverID, dest};
    lock->lockWrite();
    registrations.push_back(rd);
    lock->unlockWrite();
    return true;
}

bool MessageProcessor::unregisterReceiver(
            ClientEndPoint* cep,
            const std::string& receiverID) {
    std::vector<RegistrationData>::iterator it = find(cep, receiverID, "", 6);
    if (it == registrations.end())
        return false;
    lock->lockWrite();
    registrations.erase(it);
    lock->unlockWrite();
    return true;
}

bool MessageProcessor::processQueueMessage(GenericCMSMessage& msg) {
    //TODO: 
    return true;
}

bool MessageProcessor::processTopicMessage(GenericCMSMessage& msg) {
    //TODO: 
    return true;
}