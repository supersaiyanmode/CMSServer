#if defined(MAIN_TEST) || defined(ENABLE_ALL_TESTS)
#include <iostream>
#include <sstream>
#include <string>

#include "Server/CMSServer.h"

#include "Client/QueueReceiver.h"
#include "Client/QueueSender.h"
#include "Client/CMSServerConnection.h"

#include "Util/Thread/ThreadLogger.h"
#include "Util/Thread/Thread.h"

#include "Util/Regex/RegexMatcher.h"

class MyCMSServer: public CMSServer {
	Thread<MyCMSServer, int>* thread;
public:
    MyCMSServer(int p): CMSServer(p){
        thread = Thread<MyCMSServer, int>::createThread(this, &MyCMSServer::serve);
        thread->start(0);
    }
    
    void serve(int){
        CMSServer::serve();
    }
};

class MyQueueReceiver: public QueueReceiver {
public:
    MyQueueReceiver(CMSServerConnection& conn, const std::string& dest):
            QueueReceiver(conn, dest){
        tlog("QueueReceiver initialised!");
    }
    
    void onMessage(GenericCMSMessage& msg){
        tlog("INCOMING MESSAGE:\n"<<msg.str());
    }
};

class MyQueueSender : public QueueSender {
public:
    MyQueueSender(CMSServerConnection& conn, const std::string& dest):
            QueueSender(conn, dest){
        tlog("QueueSender initialised!");
    }
    
    void send(std::string m){
        QueueSender::send(m);
    }
};

int main(){
    MyCMSServer server(8097);
    ThreadBase::sleep(100);
    CMSServerConnection* conn = CMSServerConnection::createCMSServerConnection(
                    "127.0.0.1", 8097);
    MyQueueSender sender1(*conn, "ABC");
    MyQueueReceiver recr1(*conn, "ABC");
    sender1.send("BLAH!");
    
    ThreadBase::sleep(10000);
    return 0;
}
#endif