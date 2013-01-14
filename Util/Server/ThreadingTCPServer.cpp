#include "ThreadingTCPServer.h"

ThreadingTCPServer::ThreadingTCPServer(int p): BaseTCPServer(p){
    
}

ThreadingTCPServer::~ThreadingTCPServer(){
    if (active)
        shutdown();
}

void ThreadingTCPServer::processRequest(Connection c){
    ThreadingRequestProcessor::processRequest(c);
}