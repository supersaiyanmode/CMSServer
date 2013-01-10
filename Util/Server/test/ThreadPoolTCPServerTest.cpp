#ifdef THREAD_POOL_TCP_SERVER_UNIT_TEST
#include <vector>
#include <cstdlib>
#include <ctime>

#include "../ThreadPoolTCPServer.h"
#include "../../IO/Structure/Line/LineReader.h"
#include "../../IO/Structure/Line/LineWriter.h"
#include "../../IO/SocketIO/TCPClientSocket.h"
#include "../../Thread/Mutex.h"
#include "../../Thread/ThreadLogger.h"

std::string randomString() {
    static int inited;
    if (!(inited++)){
        std::srand(unsigned(std::time(NULL)));
    }
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string ret;
    for (int i = 0; i < 62; ++i)
        ret += alphanum[std::rand() % (sizeof(alphanum) - 1)];

    return ret;
}

class MyServer : public ThreadPoolTCPServer{
    bool destroyed;
    Thread<MyServer, int>* thread;
    MyServer(int p): ThreadPoolTCPServer(p) {
        initialise();
        thread = Thread<MyServer,int>::createThread(this, &MyServer::run);
    }
public:
    static MyServer* createMyServer(int p){
        return new MyServer(p);
    }
    
    void start(){
        destroyed = false;
        tlog("Server starting");
        thread->start(0);
    }
    
    void onIncomingConnection(Connection c){
        tlog("Got incoming Connection: "<<c.getRemoteAddress().first<<":"
                    <<c.getRemoteAddress().second);
        LineReader reader(c);
        LineWriter writer(c);
        while (true) {
            std::string in(reader.readLine());
            //tlog("<< "<<in);
            writer.writeLine(in);
            break;
        }
        reader.close();
        writer.close();
        c.close();
    }
    
    void run(int) {
        ThreadPoolTCPServer::serve();
    }
    
    void destroy() {
        ThreadPoolTCPServer::shutdown();
        thread->kill();
        thread->join();
        delete thread;
        destroyed = true;
    }
    
    ~MyServer(){
        if (!destroyed)
            destroy();
        tlog("MyServer destroyed!");
    }
};

int count = 0;
class MyClient {
    Connection conn;
    int clientId;
    Thread<MyClient, int>* thread;
    MyClient(const std::string& s, int p): conn(Connection::open(s,p)){
        thread = Thread<MyClient,int>::createThread(this, &MyClient::run);
        clientId = ++count;
        tlog(" * client ctor["<<clientId<<"@"<<this<<"]");
    }
    MyClient(const MyClient&);
    void operator=(MyClient&);
public:
    
    static MyClient* createMyClient(const std::string& s, int p){
        return new MyClient(s,p);
    }
    
    void start(){
        tlog(" * Starting Thread. this="<<this);
        thread->start(0);
    }
    
    void run(int){
        LineReader reader(conn);
        LineWriter writer(conn);
        while (true) {
            std::string line = randomString();
            writer.writeLine(line);
            std::string recd = reader.readLine();
            if (recd != line){
                tlog("<ERROR> ["<<clientId<<"]\n\tSent: "<<line<<
                                          "\n\tRecd: "<<recd);
                return;
            }else{
                tlog("<OK> ["<<clientId<<"]\n\tSent: "<<line<<
                                          "\n\tRecd: "<<recd);
            }
            break;
        }
        reader.close();
        writer.close();
        conn.close();
    }
    
    void destroy(){
        thread->kill();
    }
    
    ~MyClient() {
        delete thread;
    }
};

#define MAX 100
int main(){
    MyServer* s = MyServer::createMyServer(8090);
    s->start();

    std::vector<MyClient*> vec;
    //vec.reserve(MAX);
    for (int i=0; i< MAX; i++){
        vec.push_back(MyClient::createMyClient("127.0.0.1", 8090));
        vec[i]->start();
    }

    ThreadBase::sleep(10000);
    tlog("Test finished!");
    for (int i=0; i<MAX; i++){
        tlog("destroying client #"<<i);
        delete vec[i];
    }
    tlog ("destroying server");
    delete s;
}
#endif