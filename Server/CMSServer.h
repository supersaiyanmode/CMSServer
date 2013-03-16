#ifndef CMS_SERVER_MAIN_H
#define CMS_SERVER_MAIN_H

#include "Core/ClientHandler.h"
#include "Core/MessageProcessor.h"

class CMSServer : protected MessageProcessor, protected BridgeProcessor, public ClientHandler {
    bool destroyed;
    
protected:
    virtual bool onConnection(const Connection&) const;
    virtual void onDisconnection(const Connection&) const;
    virtual bool onReceiverRegistrationRequest();
    virtual bool onReceiverUnregistrationRequest();
    
public:
    CMSServer(int);
    virtual ~CMSServer();
    
    std::string addBridge(const CMSDestGroup&, const CMSDestination&, bool isQueue);
    
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

inline std::string CMSServer::addBridge(const CMSDestGroup& from, const CMSDestination& to, bool isQueue) {
    return BridgeProcessor::addBridge(from, to, isQueue);
}

#endif