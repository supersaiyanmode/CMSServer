#ifndef THREAD_POOL_TCP_SERVER
#define THREAD_POOL_TCP_SERVER

#include "BaseTCPServer.h"
#include "RequestProcessors/ThreadPoolRequestProcessor.h"

class ThreadPoolTCPServer : public BaseTCPServer, public ThreadPoolRequestProcessor {
    bool active;
    
    ThreadPoolTCPServer(const ThreadPoolTCPServer&);
    ThreadPoolTCPServer& operator=(const ThreadPoolTCPServer&);
    
    void processRequest(Connection);
public:
    ThreadPoolTCPServer(int, int=10,int=1024);
    virtual ~ThreadPoolTCPServer();
    
    virtual void initialise();
    virtual void shutdown();
    
protected:
    virtual void onIncomingConnection(Connection)=0;
};



//INLINE FUNCTIONS
inline void ThreadPoolTCPServer::initialise(){
    BaseTCPServer::initialise();
}

inline void ThreadPoolTCPServer::shutdown(){
    if (active){
        BaseTCPServer::shutdown();
        ThreadPoolRequestProcessor::shutdown();
        active = false;
    }
}


#endif