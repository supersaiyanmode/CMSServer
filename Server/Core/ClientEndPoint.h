#ifndef CMS_REMOTE_CLIENT_H
#define CMS_REMOTE_CLIENT_H


#include "MessageProcessor.h"
#include "../../Util/IO/Socket/Connection.h"
#include "../../Util/Thread/Thread.h"
#include "../../Util/Thread/SynchronisedQueue.h"
#include "../../Protocol/CMSMessage/GenericCMSMessage.h"


class ClientEndPoint {
public:
	ClientEndPoint(Connection &, MessageProcessor&);
	~ClientEndPoint();
	
	
	void process(int=0);
	
private:
	bool active;
	
	Thread<ClientEndPoint, int>* outThread;
	SynchronisedQueue<GenericCMSMessage>* queue;
	
	Connection& conn;
	MessageProcessor& messageProcessor;
};

#endif