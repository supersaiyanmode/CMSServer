#ifndef STATIC_PAGE_HANDLER_H
#define STATIC_PAGE_HANDLER_H

#include <map>
#include <string>

#include "../../Server/HTTP/HTTPEndPointHandler.h"

class StaticPageHandler : public HTTPEndPointHandler {
    std::string filePath;
    std::string fileContent;
    std::string mimeType;
    bool isContentReady;
public:
    StaticPageHandler();
    StaticPageHandler(const std::string &, const std::string&);
    virtual ~StaticPageHandler();
    
    virtual void onGetRequest(const HTTPRequest&, HTTPResponse&);
    virtual void onPostRequest(const HTTPRequest&, HTTPResponse&);
};

#endif