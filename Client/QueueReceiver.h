#ifndef CMS_QUEUE_RECEIVER_H
#define CMS_QUEUE_RECEIVER_H

#include "CMSClient.h"
#include "CMSServerConnection.h"

class QueueReceiver : public CMSClient {
    CMSServerConnection& conn;
    std::string destination;
    
    
    QueueReceiver(const QueueReceiver&);
    QueueReceiver& operator=(const QueueReceiver&);
protected:
    QueueReceiver(CMSServerConnection&, const std::string&);
    virtual ~QueueReceiver();
    
public:
    virtual void onMessage(GenericCMSMessage&)=0;
};
    

#endif
