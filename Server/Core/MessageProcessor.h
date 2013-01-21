#ifndef MESSAGE_PROCESSOR_H
#define MESSAGE_PROCESSOR_H

#include <map>
#include <string>

#include "../../Protocol/CMSMessage/GenericCMSMessage.h"
#include "../../Util/Thread/ReadWriteLock.h"

class ClientEndPoint;

struct RegistrationData {
	ClientEndPoint* client;
	std::string receiverID;
	std::string destination;
};

class MessageProcessor {
public:
	MessageProcessor();
	~MessageProcessor();
    
    bool registerReceiver(ClientEndPoint*, const std::string& id, const std::string& dest);
    bool unregisterReceiver(ClientEndPoint*, const std::string& id);
	
    bool processQueueMessage(GenericCMSMessage&);
    bool processTopicMessage(GenericCMSMessage&);
private:
	
    std::vector<RegistrationData>::iterator find(
        ClientEndPoint*, const std::string&, const std::string&, int fields);
    
	ReadWriteLock* lock;
	std::vector<RegistrationData> registrations;
};

#endif