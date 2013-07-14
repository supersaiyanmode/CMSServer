#ifdef THREADPOOL_HTTP_TEST_DEFINED

#include "../HTTP/ThreadPoolHTTPServer.h"

class : public HTTPEndPointHandler {
public:
    void onGetRequest(const HTTPRequest& request, HTTPResponse& response) {
        std::cout<<"HI!\n";
        response = HTTPResponse(200, "OK");
        response.write("Whoa! This works!");
    }
    
    void onPostRequest(const HTTPRequest& request, HTTPResponse& response) {
        response = HTTPResponse(200, "OK");
        response.write("Whoa! This works also!");
    }
}handler1;

class MyThreadPoolHTTPServer : public ThreadPoolHTTPServer {
    Thread<MyThreadPoolHTTPServer, int>* thread;
public:
    MyThreadPoolHTTPServer(int x): ThreadPoolHTTPServer(x) {
        std::cout<<"HI!!!\n";
        ThreadPoolHTTPServer::initialise();
        registerHandler("/test/x", &handler1);
        thread = Thread<MyThreadPoolHTTPServer, int>::createThread(this, &MyThreadPoolHTTPServer::serve);
        thread->start(0);
    }
    
    void serve(int) {
        ThreadPoolHTTPServer::serve();
    }
};

int main() {
    MyThreadPoolHTTPServer server(18090);
    std::string s;
    while (std::cin>>s) {
        if (s == "quit"){
            exit(0);
        }
    }
}

#endif