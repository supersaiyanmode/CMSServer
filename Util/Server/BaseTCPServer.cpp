#include "BaseTCPServer.h"

BaseTCPServer::BaseTCPServer(int p): ServerSkeleton(p){
    
}

BaseTCPServer::~BaseTCPServer(){
    
}

void BaseTCPServer::serve(){
    baseTCPServerActive = true;
    while (baseTCPServerActive){
        Connection c = ServerSkeleton::accept();
        processRequest(c);
    }
}