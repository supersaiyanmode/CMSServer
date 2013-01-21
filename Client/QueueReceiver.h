#ifndef CMS_QUEUE_RECEIVER_H
#define CMS_QUEUE_RECEIVER_H

#include "CMSClient.h"
#include "CMSServerConnection.h"

class QueueReceiver : public CMSClient {
    CMSServerConnection& conn;
    std::string cmsDestination;
    
    
    QueueReceiver(const QueueReceiver&);
    QueueReceiver& operator=(const QueueReceiver&);
protected:
    QueueReceiver(CMSServerConnection&, const std::string&);
    virtual ~QueueReceiver();

	const std::string& destination() const;
    
public:
    virtual void onMessage(GenericCMSMessage&)=0;
};
    

//INLINE FUNCTIONS

inline const std::string& QueueReceiver::destination() const {
	return cmsDestination;
}

#endif
