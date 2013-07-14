#ifndef POINTS_LISTER_HANDLER_H
#define POINTS_LISTER_HANDLER_H

#include "../../Server/HTTP/HTTPEndPointHandler.h"

class ManagementServer;

class PointsListerHandler : public HTTPEndPointHandler {
    ManagementServer* server;
public:
    PointsListerHandler(ManagementServer*);
    virtual ~PointsListerHandler();
    
    void onGetRequest(const HTTPRequest&, HTTPResponse&);
    void onPostRequest(const HTTPRequest&, HTTPResponse&);
};

#endif