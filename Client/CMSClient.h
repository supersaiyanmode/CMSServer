#ifndef CMS_CLIENT_H
#define CMS_CLIENT_H

#include "../Protocol/CMSMessage/GenericCMSMessage.h"
#include "../Util/Random/Sequential.h"

class CMSClient {
    UniqueID clientID;
public:
    CMSClient();
    ~CMSClient();
    
    UniqueID id() const;
    
    virtual void onAcknowledgement(UniqueID, GenericCMSMessage&) {};
    virtual void onError(UniqueID, GenericCMSMessage&) {};
    virtual void onMessage(GenericCMSMessage&) {};
};






//INLINE FUNCTIONS
inline UniqueID CMSClient::id() const{
    return clientID;
}

#endif