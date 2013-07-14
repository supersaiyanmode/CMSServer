#ifndef CMS_REMOTE_CLIENT_H
#define CMS_REMOTE_CLIENT_H

#include <vector>
#include <string>

#include "MessageProcessor.h"
#include "BridgeProcessor.h"
#include "../../Util/IO/SocketIO/Connection.h"
#include "../../Util/Thread/Thread.h"
#include "../../Util/Thread/SynchronisedQueue.h"
#include "../../Protocol/CMSMessage/GenericCMSMessage.h"

class ClientEndPoint {
public:
	ClientEndPoint(Connection &, MessageProcessor&, BridgeProcessor&);
	~ClientEndPoint();
	
	
	void processIncoming(int=0);
	void processOutgoing(int=0);
	
	void addOutboundMessage(GenericCMSMessage& msg);
	
private:
	bool active;
	std::vector<std::string> receiverIDs;
	
	Thread<ClientEndPoint, int>* outThread;
	SynchronisedQueue<GenericCMSMessage>* queue;
	
	Connection& conn;
	MessageProcessor& messageProcessor;
    BridgeProcessor& bridgeProcessor;
};

#endif