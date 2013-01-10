#include "ThreadPoolTCPServer.h"

ThreadPoolTCPServer::ThreadPoolTCPServer(int port, int workers, int queueSize):
        BaseTCPServer(port), ThreadPoolRequestProcessor(workers,queueSize) {
    
}

ThreadPoolTCPServer::~ThreadPoolTCPServer(){
    if (active)
        shutdown();
}

void ThreadPoolTCPServer::initialise(){
    BaseTCPServer::initialise();
}

void ThreadPoolTCPServer::shutdown(){
    if (active){
        BaseTCPServer::shutdown();
        ThreadPoolRequestProcessor::shutdown();
        active = false;
    }
}

void ThreadPoolTCPServer::processRequest(Connection c){
    ThreadPoolRequestProcessor::processRequest(c);
}