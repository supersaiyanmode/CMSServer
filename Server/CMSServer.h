#ifndef CMS_SERVER_MAIN_H
#define CMS_SERVER_MAIN_H

#include "Core/ClientHandler.h"
#include "Core/MessageProcessor.h"

class CMSServer : public ClientHandler {
    bool destroyed;
	MessageProcessor mp;
public:
    CMSServer(int);
    virtual ~CMSServer();
    
    void destroy();
    
    void serve();
};

#endif