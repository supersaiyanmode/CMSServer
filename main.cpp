#if defined(MAIN_TEST) || defined(ENABLE_ALL_TESTS)
#include <iostream>
#include <sstream>
#include <string>

#include "Server/CMSServer.h"

#include "Client/QueueReceiver.h"
#include "Client/QueueSender.h"
#include "Client/TopicSubscriber.h"
#include "Client/TopicPublisher.h"
#include "Client/CMSServerConnection.h"

#include "Util/Thread/ThreadLogger.h"
#include "Util/Thread/Thread.h"
#include "Util/String/StringUtils.h"
#include "Util/DataType/Primitive/Number.h"


//TODO:
//1. Move RegistrationData out to a new class with RWLocks
//2. Like MessageProcessor, have BridgeProcessor as well


class MyCMSServer: public CMSServer {
	Thread<MyCMSServer, int>* thread;
public:
    MyCMSServer(int p): CMSServer(p){
        addBridge(CMSDestGroup("A.B.C.>"), CMSDestination("X.Y.Z"), true);
        addBridge(CMSDestGroup("A.B.X.>"), CMSDestination("P.Q.R"), false);
        
        thread = Thread<MyCMSServer, int>::createThread(this, &MyCMSServer::serve);
        thread->start(0);
    }
    
    bool onConnection(const Connection& c) const{
        tlog("Remote client connected from "<<c.remoteAddressStr());
        return true;
    }
    
    void onDisconnection(const Connection& c) const {
        tlog("Remote client disconnected: "<<c.remoteAddressStr());
    }
    
    bool onReceiverRegistrationRequest() {
        tlog("Registration request");
        return true;
    }
    
    bool onReceiverUnregistrationRequest() {
        tlog("Unregistration request");
        return true;
    }
    
    void serve(int){
        CMSServer::serve();
    }
};

class MyQueueReceiver: public QueueReceiver {
public:
    MyQueueReceiver(CMSServerConnection& conn, const std::string& dest):
            QueueReceiver(conn, dest){
        tlog("QueueReceiver initialised. Receiver ID: "<<id());
    }
    
    void onMessage(GenericCMSMessage& msg){
        tlog("Got ["<<(std::string)destination()<<"]: "<<msg.message());
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

class MyTopicSubscriber: public TopicSubscriber {
public:
    MyTopicSubscriber(CMSServerConnection& conn, const std::string& dest):
            TopicSubscriber(conn, dest){
        tlog("TopicSubscriber initialised. Receiver ID: "<<id());
    }
    
    void onMessage(GenericCMSMessage& msg){
        tlog("Got ["<<(std::string)destination()<<"]: "<<msg.message());
    }
};

class MyTopicPublisher : public TopicPublisher {
public:
    MyTopicPublisher(CMSServerConnection& conn, const std::string& dest):
            TopicPublisher(conn, dest){
        tlog("TopicPublisher initialised!");
    }
    
    void publish(std::string m){
        TopicPublisher::publish(m);
    }
};

int main(int argc, char ** argv){
    if (argc != 3){
        std::cout<<"Invalid arguments.\n";
        return 1;
    }
    if (std::string(argv[1]) == "-server") {
        Number port(0);
        if (!Number::parse(argv[2], port) || (long)port < 1024 || (long)port > 65535) {
            std::cout<<"Not a valid port number.\n";
            return 1;
        }
        MyCMSServer server((int)(long)port);
        tlog ("Server started on port "<<(long)port);
        std::string line;
        while (std::getline(std::cin, line)){
            if (line == "quit")
                break;
            else if (line == "")
                continue;
            else
                tlog("Unrecognised command.");
        }
    } else {
        Number port(0);
        if (!Number::parse(argv[2], port) || (long)port < 1024 || (long)port > 65535) {
            std::cout<<"Not a valid port number.\n";
            return 1;
        }
        CMSServerConnection* conn = CMSServerConnection::createCMSServerConnection(
            argv[1], (int)(long)port);
        tlog ("Connected to Server at "<<argv[1]<<" on port "<<(long)port);
        std::vector<CMSClient*> receivers;
        std::string command, opt1, opt2;
        while (conn->readable() && conn->writable()){
            (std::cout<<"> ").flush();
            std::cin>>command;
            if (command == "quit")
                break;
            else if (command == "receive"){
                std::cin>>opt1;
                CMSClient* r = new MyQueueReceiver(*conn, opt1);
                receivers.push_back(r);
            } else if (command == "send"){
                std::cin>>opt1;
                MyQueueSender s(*conn, opt1);
                std::cin>>command;
                s.send(StringUtils::trim(command));
            } else if (command == "publish"){
                std::cin>>opt1;
                MyTopicPublisher s(*conn, opt1);
                std::cin>>command;
                s.publish(StringUtils::trim(command));
            } else if (command == "subscribe") {
                std::cin>>opt1;
                CMSClient* r = new MyTopicSubscriber(*conn, opt1);
                receivers.push_back(r);
            } 
            else
                tlog("Unrecognised command!");
        }
        for (std::vector<CMSClient*>::iterator it=receivers.begin();
                    it != receivers.end(); it++){
            delete *it;
        }
        delete conn;
    }
    return 0;
}
#endif