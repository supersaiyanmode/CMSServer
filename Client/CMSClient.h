#ifndef CMS_CLIENT_H
#define CMS_CLIENT_H

#include "../Protocol/CMSMessage/GenericCMSMessage.h"
#include "../Protocol/CMSDestination/CMSDestination.h"
#include "../Util/Random/Sequential.h"

class CMSClient {
    UniqueID clientID;
public:
    CMSClient();
    virtual ~CMSClient();
    
    UniqueID id() const;
	virtual const CMSDestination& destination() const = 0;
    
    virtual void onAcknowledgement(UniqueID, GenericCMSMessage&) {}
    virtual void onError(UniqueID, GenericCMSMessage&) {}
    virtual void onMessage(GenericCMSMessage&) {}
    
    virtual void onDisconnect(){}
};






//INLINE FUNCTIONS
inline UniqueID CMSClient::id() const{
    return clientID;
}

#endif