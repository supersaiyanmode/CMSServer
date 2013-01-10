#ifndef THREAD_POOL_REQUEST_PROCESSOR
#define THREAD_POOL_REQUEST_PROCESSOR

#include "RequestProcessor.h"
#include "../../Thread/Thread.h"
#include "../../Thread/ThreadPool.h"
#include "../../IO/SocketIO/Connection.h"
#include <vector>

class ThreadPoolRequestProcessor: public RequestProcessor {
    bool active;
    ThreadPool<ThreadPoolRequestProcessor, Connection>* threadPool;
protected:
    virtual void processRequest(Connection);
    virtual void onIncomingConnection(Connection)=0;

    ThreadPoolRequestProcessor(int=10, int=1024);
    virtual ~ThreadPoolRequestProcessor();
    
    void shutdown();
};


#endif