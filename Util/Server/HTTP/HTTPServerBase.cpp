#include "HTTPServerBase.h"
    
bool HTTPServerBase::registerHandler(const HTTPEndPoint& path, HTTPEndPointHandler* obj) {
    if (getHandler(path))
        return false;
    handlers[path] = obj;
    return true;
}

HTTPEndPointHandler* HTTPServerBase::getHandler(const HTTPEndPoint& path) {
    std::map<HTTPEndPoint, HTTPEndPointHandler*>::iterator pos = handlers.find(path);
    if (pos == handlers.end())
        return NULL;
    return pos->second;
}
