#ifndef HTTP_END_POINT_HANDLER_H
#define HTTP_END_POINT_HANDLER_H

#include "protocol/HTTPRequest.h"
#include "protocol/HTTPResponse.h"

class HTTPEndPointHandler {
public:
    virtual void onGetRequest(const HTTPRequest&, HTTPResponse&);
    virtual void onPostRequest(const HTTPRequest&, HTTPResponse&);
};

#endif