#include "PointsHandler.h"
#include "../ManagementServer.h"
#include "../../String/StringUtils.h"

PointsHandler::PointsHandler(ManagementServer* s): server(s) {
    
}

PointsHandler::~PointsHandler() {}

void PointsHandler::onGetRequest(const HTTPRequest& request, HTTPResponse& response) {
    response = HTTPResponse(405, "Method Not Allowed");
}

void PointsHandler::onPostRequest(const HTTPRequest& request, HTTPResponse& response) {
    std::map<std::string, Manageable*> manageableMap(server->getPoints());
    std::map<std::string, std::string> queryMap(request.queryMap());
    
    std::string manageableId = StringUtils::trim(queryMap["id"]);
    if (manageableId == "") {
        response = HTTPResponse(404, "Not Found");
        return;
    }
    
    Manageable* manageable = manageableMap[manageableId];
    if (!manageable) {
        response = HTTPResponse(404, "Not Found");
        return;
    }
    
    std::vector<std::string> input = StringUtils::splitAny(request.body(), "\n");
    std::string output;
    
    if (manageable->invoke(input, output)) {
        response = HTTPResponse(200,"OK");
        response.write(output);
    } else {
        response = HTTPResponse(200, "OK");
        response.write("Process invocation was unsuccessful.");
    }
}