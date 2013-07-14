#include "HTTPEndPointHandler.h"

void HTTPEndPointHandler::onGetRequest(const HTTPRequest& request, HTTPResponse& response) {
    response = HTTPResponse(405, "Method Not Allowed");
}

void HTTPEndPointHandler::onPostRequest(const HTTPRequest& request, HTTPResponse& response) {
    response = HTTPResponse(405, "Method Not Allowed");    
}
