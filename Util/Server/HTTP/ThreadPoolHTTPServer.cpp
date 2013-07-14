#include <iostream>

#include "ThreadPoolHTTPServer.h"
#include "HTTPParser.h"
#include "../../IO/Structure/Block/BlockWriter.h"

ThreadPoolHTTPServer::ThreadPoolHTTPServer(int port, int workers, int queueSize):
        ThreadPoolTCPServer(port, workers,queueSize) {
    
}

ThreadPoolHTTPServer::~ThreadPoolHTTPServer(){
    if (active)
        shutdown();
}

void ThreadPoolHTTPServer::onIncomingConnection(Connection c){
    HTTPParser parser(c);
    if (!parser.parse()) {
        std::cout<<"Invalid HTTP Request.\n";
        c.write(HTTPResponse(400, "Bad Request").str());
        c.close();
        return;
    }
    HTTPRequest request(parser.getRequest());
    HTTPResponse response;
    std::cout<<"Trying to get handler: "<<request.url()<<std::endl;;
    HTTPEndPointHandler* handler = HTTPServerBase::getHandler(request.url());
    if (!handler) {
        c.write(HTTPResponse(404, "Not Found").str());
        c.close();
        std::cout<<"Not found!\n";
        return;
    }
    std::cout<<"Got handler\n";
    switch (request.method()) {
        case GET:
            handler->onGetRequest(request, response);
            break;
        case POST:
            handler->onPostRequest(request, response);
            break;
        default:
            response = HTTPResponse(405, "Method Not Allowed");
            break;
    }
    c.write(response.str());
    c.close();
}