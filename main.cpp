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

class MyCMSServer: public CMSServer {
	
};

class MyQueueReceiver: public QueueReceiver {
public:
    MyQueueReceiver(CMSServerConnection& conn, const std::string& dest):
            QueueReceiver(conn, dest){
        tlog("QueueReceiver initialised!");
    }
};

class MyQueueSender : public QueueSender {
public:
    MyQueueSender(CMSServerConnection& conn, const std::string& dest):
            QueueSender(conn, dest){
        tlog("QueueSender initialised!");
    }
};

int main(){
    
    return 0;
}
#endif