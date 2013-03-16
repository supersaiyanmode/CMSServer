#ifndef CLIENT_HANDLER_H
#define CLIENT_HANDLER_H

#include "../../Util/Server/ThreadingTCPServer.h"
#include "MessageProcessor.h"
#include "BridgeProcessor.h"
    
class ClientHandler : public ThreadingTCPServer {
public:
    ClientHandler(int, MessageProcessor&, BridgeProcessor&);
    virtual ~ClientHandler();
    
    virtual void initialise();
    void serve();
    virtual void shutdown();
    
protected:
    void onIncomingConnection(Connection);
	virtual bool onConnection(const Connection&) const = 0;
    virtual void onDisconnection(const Connection&) const = 0;
private:
	MessageProcessor& messageProcessor;
    BridgeProcessor& bridgeProcessor;
};

#endif