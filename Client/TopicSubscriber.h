#ifndef CMS_TOPIC_SUBSCRIBER_H
#define CMS_TOPIC_SUBSCRIBER_H

#include "CMSClient.h"
#include "CMSServerConnection.h"
#include "../Protocol/CMSDestination/CMSDestination.h"
class TopicSubscriber : public CMSClient {
    CMSServerConnection& conn;
    CMSDestination cmsDestination;
    
    
    TopicSubscriber(const TopicSubscriber&);
    TopicSubscriber& operator=(const TopicSubscriber&);
protected:
    TopicSubscriber(CMSServerConnection&, const std::string&);
    virtual ~TopicSubscriber();

	const CMSDestination& destination() const;
    
public:
    virtual void onMessage(GenericCMSMessage&)=0;
    virtual void onDisconnect(){}
};
    

//INLINE FUNCTIONS

inline const CMSDestination& TopicSubscriber::destination() const {
	return cmsDestination;
}

#endif
