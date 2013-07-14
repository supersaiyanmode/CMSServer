#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include <map>
#include <string>

#include "HTTPEndPoint.h"

enum HTTPMethod { GET, POST, PUT, DELETE, HEAD};

class HTTPRequest {
    HTTPMethod m_method;
    HTTPEndPoint m_url;
    std::string m_version;
    std::map<std::string, std::string> m_queryMap;
    std::map<std::string, std::string> m_headers;
    std::string m_body;
    bool m_valid;
public:
    HTTPRequest();
    HTTPRequest(HTTPMethod, HTTPEndPoint, std::string, std::map<std::string, std::string>, 
                        std::map<std::string, std::string>, std::string);
    bool valid();
    
    HTTPMethod method() const;
    std::string version() const;
    HTTPEndPoint url() const;
    std::string body() const;
    std::map<std::string, std::string> queryMap() const;
    
    bool bodyPresent() const;
    int length();
};

inline HTTPMethod HTTPRequest::method() const {
    return m_method;
}
inline std::string HTTPRequest::version() const {
    return m_version;
}
inline HTTPEndPoint HTTPRequest::url() const {
    return m_url;
}
inline std::string HTTPRequest::body() const {
    return m_body;
}
inline bool HTTPRequest::valid() {
    return m_valid;
}

inline std::map<std::string, std::string> HTTPRequest::queryMap() const {
    return m_queryMap;
}

#endif