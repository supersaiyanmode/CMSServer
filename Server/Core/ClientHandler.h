#ifndef CLIENT_HANDLER_H
#define CLIENT_HANDLER_H

#include "../../Util/Server/ThreadingTCPServer.h"
#include "MessageProcessor.h"

class ClientHandler : public ThreadingTCPServer {
public:
    ClientHandler(int, MessageProcessor&);
    virtual ~ClientHandler();
    
    virtual void initialise();
    virtual void shutdown();
    
protected:
    void onIncomingConnection(Connection);
	
private:
	MessageProcessor& messageProcessor;
};

#endif