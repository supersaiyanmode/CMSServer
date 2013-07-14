#ifndef MANANGEMENT_SERVER_H
#define MANANGEMENT_SERVER_H

#include <string>
#include <map>

#include "../Server/HTTP/ThreadPoolHTTPServer.h"
#include "Manageable.h"
#include "HTTPEndPointHandlers/StaticPageHandler.h"

class ManagementServer : public ThreadPoolHTTPServer {
    std::map<std::string, Manageable*> manageableMap;
    
    //static handlers
    std::map<std::string, HTTPEndPointHandler*> staticHandlers;
    
    //Points Handler
    HTTPEndPointHandler* pointsListerHandler;
    
    //Point Handler
    HTTPEndPointHandler* pointsHandler;
    
public:
    ManagementServer(int x);
    virtual ~ManagementServer();
    
    void initialise();
    void serve();

    void registerObject(std::string, Manageable*);
    void unregisterObject(Manageable*);
    
    std::map<std::string, Manageable*> getPoints();
};

#endif