#ifndef QUEUE_SENDER_H
#define QUEUE_SENDER_H

#include "CMSClient.h"
#include "CMSServerConnection.h"
#include "../Protocol/CMSMessage/Header/CMSHeaderSet.h"
#include "../Protocol/CMSMessage/GenericCMSMessage.h"
#include "../Util/Thread/Mutex.h"
#include "../Util/Thread/Condition.h"

class QueueSender : public CMSClient {
    CMSServerConnection& conn;
    std::string destination;
    
    Mutex *sendLock, *ackLock;
    Condition *ackArrived;
    
    GenericCMSMessage response;
    UniqueID waitID;
    int waitStatus;
    
    QueueSender(const QueueSender&);
    QueueSender& operator=(const QueueSender&);
    
protected:
    QueueSender(CMSServerConnection&, const std::string&);
    ~QueueSender();
    
    void onAcknowledgement(UniqueID, GenericCMSMessage&);
    void onError(UniqueID, GenericCMSMessage&);
    void onMessage(GenericCMSMessage&);

public:
    bool send(const CMSHeaderSet&, const std::string&);
    bool send(const std::string&);
    
};
#endif