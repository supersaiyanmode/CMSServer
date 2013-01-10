#include <iostream>
#include "ServerSkeleton.h"
ServerSkeleton::ServerSkeleton(int p):serverSocket(p){
    
}


ServerSkeleton::ServerSkeleton(const ServerSkeleton& other):
        serverSocket(other.serverSocket){
    
}

ServerSkeleton& ServerSkeleton::operator=(const ServerSkeleton& other){
    this->serverSocket = other.serverSocket;
    return *this;
}

ServerSkeleton::~ServerSkeleton(){
    
}

void ServerSkeleton::initialise(){
    serverSocket.initialise();
}

Connection ServerSkeleton::accept(){
    return serverSocket.accept();
}

void ServerSkeleton::shutdown(){
    serverSocket.close();
}