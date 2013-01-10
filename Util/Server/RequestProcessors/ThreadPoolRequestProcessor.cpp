#include "ThreadPoolRequestProcessor.h"

void ThreadPoolRequestProcessor::processRequest(Connection c){
    threadPool->execute(this, &ThreadPoolRequestProcessor::onIncomingConnection, c);
}

ThreadPoolRequestProcessor::ThreadPoolRequestProcessor(int workers, int queueSize) { //default 10
    threadPool = ThreadPool<ThreadPoolRequestProcessor, Connection>::createThreadPool(
        workers, queueSize);
    active = true;
    threadPool->start();
}

ThreadPoolRequestProcessor::~ThreadPoolRequestProcessor(){
    if (active)
        shutdown();
}

void ThreadPoolRequestProcessor::shutdown(){
    if (active){
        active = false;
        delete threadPool;
    }
}