#ifndef THREADING_TCP_SERVER_H
#define THREADING_TCP_SERVER_H

#include "BaseTCPServer.h"
#include "RequestProcessors/ThreadingRequestProcessor.h"

class ThreadingTCPServer : public ThreadingRequestProcessor, public BaseTCPServer {
    bool active;
    
    ThreadingTCPServer(const ThreadingTCPServer&);
    ThreadingTCPServer& operator=(const ThreadingTCPServer&);
    
    void processRequest(Connection);
public:
    ThreadingTCPServer(int);
    virtual ~ThreadingTCPServer();
    
    void initialise();
    void shutdown();
    
protected:
    virtual void onIncomingConnection(Connection)=0;
};

#endif