#include "CMSServer.h"

CMSServer::CMSServer(int p): ClientHandler(p, *this, *this) {
    destroyed = false;
    ClientHandler::initialise();
}

CMSServer::~CMSServer() {
    if (!destroyed)
        destroy();
}

void CMSServer::destroy() {
    if (destroyed)
        return;
    ClientHandler::shutdown();
    destroyed = true;
}
    
void CMSServer::serve() {
    ClientHandler::serve();
}