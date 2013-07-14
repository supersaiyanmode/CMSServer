#ifndef HTTP_SERVER_BASE_H
#define HTTP_SERVER_BASE_H

#include <map>

#include "HTTPEndPointHandler.h"
#include "protocol/HTTPEndPoint.h"

class HTTPServerBase {
    std::map<HTTPEndPoint, HTTPEndPointHandler*> handlers;
public:
    
    bool registerHandler(const HTTPEndPoint&, HTTPEndPointHandler*);
    HTTPEndPointHandler* getHandler(const HTTPEndPoint& path);
};

#endif
