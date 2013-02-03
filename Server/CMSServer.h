#ifndef CMS_SERVER_MAIN_H
#define CMS_SERVER_MAIN_H

#include "Core/ClientHandler.h"
#include "Core/MessageProcessor.h"

class CMSServer : public MessageProcessor, public ClientHandler {
    bool destroyed;
public:
    CMSServer(int);
    virtual ~CMSServer();
    
    virtual bool onConnection(const Connection&) const;
    virtual void onDisconnection(const Connection&) const;
    virtual bool onReceiverRegistrationRequest();
    virtual bool onReceiverUnregistrationRequest();
    
    
    void destroy();
    
    void serve();
};



//INLINE

inline bool CMSServer::onConnection(const Connection&) const {
    return true;
}

inline void CMSServer::onDisconnection(const Connection&) const {
    
}

inline bool CMSServer::onReceiverRegistrationRequest() {
    return true;
}

inline bool CMSServer::onReceiverUnregistrationRequest() {
    return true;
}

#endif