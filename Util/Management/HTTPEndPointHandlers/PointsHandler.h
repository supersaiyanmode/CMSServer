#ifndef POINTS_HANDLER_H
#define POINTS_HANDLER_H

#include "../../Server/HTTP/HTTPEndPointHandler.h"

class ManagementServer;

class PointsHandler : public HTTPEndPointHandler {
    ManagementServer* server;
public:
    PointsHandler(ManagementServer*);
    virtual ~PointsHandler();
    
    virtual void onGetRequest(const HTTPRequest&, HTTPResponse&);
    virtual void onPostRequest(const HTTPRequest&, HTTPResponse&);
};


#endif