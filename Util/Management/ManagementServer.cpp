#include "ManagementServer.h"
#include "HTTPEndPointHandlers/PointsListerHandler.h"
#include "HTTPEndPointHandlers/PointsHandler.h"

ManagementServer::ManagementServer(int x) : ThreadPoolHTTPServer(x){
    ManagementServer::initialise();
}

void ManagementServer::initialise() {
    ThreadPoolHTTPServer::initialise();
    StaticPageHandler* mainPageHandler = new StaticPageHandler("StaticWebContent/index.html", "text/html");
    staticHandlers["StaticWebContent/index.html"] = mainPageHandler;
    ThreadPoolHTTPServer::registerHandler("/", mainPageHandler);
    
    PointsListerHandler* pointsListerHandler = new PointsListerHandler(this);
    ThreadPoolHTTPServer::registerHandler("/points", pointsListerHandler);
    this->pointsListerHandler = pointsListerHandler;
    
    PointsHandler* pointsHandler = new PointsHandler(this);
    ThreadPoolHTTPServer::registerHandler("/point", pointsHandler);
    this->pointsHandler = pointsHandler;
}

void ManagementServer::serve() {
    ThreadPoolHTTPServer::serve();
}

void ManagementServer::registerObject(std::string path, Manageable* obj) {
    manageableMap[path] = obj;
}

ManagementServer::~ManagementServer() {
    for (std::map<std::string, HTTPEndPointHandler*>::iterator it=staticHandlers.begin();
            it != staticHandlers.end(); it++) {
        delete it->second;
    }
}

std::map<std::string, Manageable*> ManagementServer::getPoints() {
    return manageableMap;
}