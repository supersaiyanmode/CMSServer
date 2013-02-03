#include "ClientHandler.h"
#include "../../Util/Thread/ThreadLogger.h"
#include "../../Protocol/CMSMessage/GenericCMSMessage.h"
#include "ClientEndPoint.h"


ClientHandler::ClientHandler(int p, MessageProcessor& mp):ThreadingTCPServer(p),
                messageProcessor(mp) {
    
}

ClientHandler::~ClientHandler(){
    
}

void ClientHandler::initialise() {
    ThreadingTCPServer::initialise();
}

void ClientHandler::serve() {
    ThreadingTCPServer::serve();
}

void ClientHandler::shutdown() {
    ThreadingTCPServer::shutdown();
}

void ClientHandler::onIncomingConnection(Connection c) {
    if (!this->onConnection(c))
        return;

    ClientEndPoint cep(c, messageProcessor);
    cep.processIncoming();
    
    this->onDisconnection(c);
}

