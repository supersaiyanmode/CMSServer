#ifndef THREAD_POOL_HTTP_SERVER
#define THREAD_POOL_HTTP_SERVER

#include "../ThreadPoolTCPServer.h"
#include "HTTPServerBase.h"

class ThreadPoolHTTPServer : public ThreadPoolTCPServer, public HTTPServerBase {
    bool active;
    
    ThreadPoolHTTPServer(const ThreadPoolHTTPServer&);
    ThreadPoolHTTPServer& operator=(const ThreadPoolHTTPServer&);
    
    void onIncomingConnection(Connection);
public:
    ThreadPoolHTTPServer(int, int=10,int=1024);
    virtual ~ThreadPoolHTTPServer();
    
    virtual void initialise();
    virtual void shutdown();
};



//INLINE FUNCTIONS
inline void ThreadPoolHTTPServer::initialise(){
    ThreadPoolTCPServer::initialise();
}

inline void ThreadPoolHTTPServer::shutdown(){
    if (active){
        ThreadPoolHTTPServer::shutdown();
        active = false;
    }
}


#endif