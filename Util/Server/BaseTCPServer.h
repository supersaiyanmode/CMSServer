#ifndef BASE_TCP_SERVER_H
#define BASE_TCP_SERVER_H

#include "ServerSkeleton.h"
#include "RequestProcessors/RequestProcessor.h"

class BaseTCPServer : public ServerSkeleton, public RequestProcessor {
    bool baseTCPServerActive;
public:
    BaseTCPServer(int);
    virtual ~BaseTCPServer();
    
    virtual void processRequest(Connection)=0;
    
    void serve();
    void shutdown();
};



//INLINE FUNCTIONS

inline void BaseTCPServer::shutdown(){
    baseTCPServerActive = false;
    ServerSkeleton::shutdown();
}

#endif