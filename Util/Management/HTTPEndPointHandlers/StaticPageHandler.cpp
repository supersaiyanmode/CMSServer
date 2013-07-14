#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "StaticPageHandler.h"

std::pair<std::string, std::string> mimePairs[] = {
    std::make_pair(".html", "text/html")
};

std::map<std::string, std::string> mimeMap(mimePairs, mimePairs + sizeof(mimePairs)/sizeof(mimePairs[0]));

StaticPageHandler::StaticPageHandler() {
    fileContent = "Bad!";
    isContentReady = true;
}

StaticPageHandler::StaticPageHandler(const std::string& path, const std::string& mime):
            filePath(path), mimeType(mime) {
    
}

StaticPageHandler::~StaticPageHandler() {}

void StaticPageHandler::onGetRequest(const HTTPRequest& request, HTTPResponse& response) {
    std::cout<<"On Get Request!\n";
    if (false && isContentReady) {
        response.setContentType(mimeType);
        response.write(fileContent);
        return;
    }
    
    //TODO: Have a lock here!
    std::ifstream inFile(filePath.c_str());
    if (inFile.bad()) {
        response = HTTPResponse(404, "Not Found");
        return;
    } else {
        std::stringstream buffer;
        buffer<<inFile.rdbuf();
        fileContent = buffer.str();
        isContentReady = true;
        response.setContentType(mimeType);
        response.write(fileContent);
    }
}

void StaticPageHandler::onPostRequest(const HTTPRequest& req, HTTPResponse& resp) {
    onGetRequest(req,resp);
}