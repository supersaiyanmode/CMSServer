#include "PointsListerHandler.h"
#include "../ManagementServer.h"

PointsListerHandler::PointsListerHandler(ManagementServer* s): server(s) {
    
}

PointsListerHandler::~PointsListerHandler() {}


void PointsListerHandler::onGetRequest(const HTTPRequest& request, HTTPResponse& response) {
    response = HTTPResponse(405, "Method Not Allowed");
}

void PointsListerHandler::onPostRequest(const HTTPRequest& request, HTTPResponse& response) {
    std::map<std::string, Manageable*> manageableMap(server->getPoints());
    
    response.setContentType("application/json");
    
    std::string result = "[\n";
    for (std::map<std::string, Manageable*>::iterator it=manageableMap.begin(); it!=manageableMap.end(); it++){
        //TODO: JSON Escape here.
        
        result += "{\"path\": \"" + it->first + "\", \"parameters\": [";
        
        const std::vector<ManageableObjectParameter>& params = it->second->parametersInfo();
        
        for (std::vector<ManageableObjectParameter>::const_iterator it=params.begin(); it!= params.end(); it++) {
            result += "{\"name\": \"" + it->name() + "\", " +
                        "\"description\": \"" + it->description() + "\"}";
            if (&*it != &params.back()) {
                result += ",";
            }
        }
        
        result += "]\n}\n";
    }
    result += "]\n";
    
    response.write(result);
    
}