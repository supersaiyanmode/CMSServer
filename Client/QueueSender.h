#ifndef QUEUE_SENDER_H
#define QUEUE_SENDER_H

#include "CMSServerConnection.h"
#include "../Protocol/CMSMessage/Header/CMSHeaderSet.h"
#include "../Protocol/CMSMessage/GenericCMSMessage.h"
#include "../Util/Thread/Mutex.h"
#include "../Util/Thread/Condition.h"

class QueueSender {
    CMSServerConnection& conn;
    std::string destination;
    
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