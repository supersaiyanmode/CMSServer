#ifndef THREADING_REQUEST_PROCESSOR_H
#define THREADING_REQUEST_PROCESSOR_H

#include "RequestProcessor.h"
#include "../../Thread/Thread.h"
#include "../../IO/SocketIO/Connection.h"
#include <vector>


class ThreadingRequestProcessor : public RequestProcessor {
    bool active;
    std::vector<Thread<ThreadingRequestProcessor, Connection>*> threads;
protected:
    virtual void processRequest(Connection);
    virtual void onIncomingConnection(Connection)=0;
    ThreadingRequestProcessor();
    virtual ~ThreadingRequestProcessor();
    
    void shutdown();
};

typedef Thread<ThreadingRequestProcessor, Connection> TRPThread;
#endif