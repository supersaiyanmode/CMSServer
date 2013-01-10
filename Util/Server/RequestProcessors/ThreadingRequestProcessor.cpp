#include "ThreadingRequestProcessor.h"


ThreadingRequestProcessor::ThreadingRequestProcessor(): active(true) {
    
}

void ThreadingRequestProcessor::processRequest(Connection c){
    TRPThread* t = Thread<ThreadingRequestProcessor, Connection>::
                        createThread(this, 
                        &ThreadingRequestProcessor::onIncomingConnection);
    t->start(c);
    threads.push_back(t);
}

ThreadingRequestProcessor::~ThreadingRequestProcessor() {
    if (active)
        shutdown();
    for (std::vector<TRPThread*>::iterator it=threads.begin();
                it!=threads.end(); it++)
         delete *it;
}

void ThreadingRequestProcessor::shutdown(){
    if (!active)
        return;
    for (std::vector<TRPThread*>::iterator it=threads.begin();
                it!=threads.end(); it++)
         (*it)->kill();
    active = true;
}