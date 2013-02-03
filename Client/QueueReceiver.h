#ifndef CMS_QUEUE_RECEIVER_H
#define CMS_QUEUE_RECEIVER_H

#include "CMSClient.h"
#include "CMSServerConnection.h"
#include "../Protocol/CMSDestination/CMSDestination.h"
class QueueReceiver : public CMSClient {
    CMSServerConnection& conn;
    CMSDestination cmsDestination;
    
    
    QueueReceiver(const QueueReceiver&);
    QueueReceiver& operator=(const QueueReceiver&);
protected:
    QueueReceiver(CMSServerConnection&, const std::string&);
    virtual ~QueueReceiver();

	const CMSDestination& destination() const;
    
public:
    virtual void onMessage(GenericCMSMessage&)=0;
    virtual void onDisconnect(){}
};
    

//INLINE FUNCTIONS

inline const CMSDestination& QueueReceiver::destination() const {
	return cmsDestination;
}

#endif
