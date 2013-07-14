#include <algorithm>

#include "HTTPRequest.h"
#include "../../../DataType/Primitive/Number.h"
#include "../../../String/StringUtils.h"


HTTPRequest::HTTPRequest(): m_valid(false) {}

HTTPRequest::HTTPRequest(HTTPMethod m, HTTPEndPoint url, std::string version,
        std::map<std::string, std::string> queryMap, 
        std::map<std::string, std::string> headers, std::string body):
        m_method(m), m_url(url), m_version(version), m_queryMap(queryMap), m_body(body), m_valid(true) {
    for (std::map<std::string, std::string>::const_iterator it=headers.begin(); it!=headers.end(); it++) {
        m_headers[StringUtils::toLower(it->first)] = it->second;
    }
}


bool HTTPRequest::bodyPresent() const {
    throw 1;
    std::map<std::string, std::string>::const_iterator it = m_headers.find("content-length");
    if (it == m_headers.end())
        return false;
    Number num(0);
    
}

int HTTPRequest::length() {
    throw 1;
    if (bodyPresent()) {
        
    }
}