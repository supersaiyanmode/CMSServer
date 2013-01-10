#include "ThreadingTCPServer.h"

ThreadingTCPServer::ThreadingTCPServer(int p): BaseTCPServer(p){
    
}

ThreadingTCPServer::~ThreadingTCPServer(){
    if (active)
        shutdown();
}

void ThreadingTCPServer::initialise(){
    active = true;
    BaseTCPServer::initialise();
}

void ThreadingTCPServer::shutdown(){
    if (active) {
        BaseTCPServer::shutdown();
        ThreadingRequestProcessor::shutdown();
        active = false;
    }
}

void ThreadingTCPServer::processRequest(Connection c){
    ThreadingRequestProcessor::processRequest(c);
}