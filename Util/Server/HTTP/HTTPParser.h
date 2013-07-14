#ifndef HTTP_PARSER_H
#define HTTP_PARSER_H

#include <map>

#include "../../IO/InputOutputCapable.h"
#include "protocol/HTTPRequest.h"

class HTTPParser {
    HTTPRequest request;
    InputOutputCapable& device;
    std::string errorMessage;
public:
    HTTPParser(InputOutputCapable& c);
    
    bool parse();
    HTTPRequest getRequest();
    
    static std::map<std::string, std::string> parseQueryString(std::string);
    static std::string decodeURIComponent(std::string);
};


inline HTTPRequest HTTPParser::getRequest() {
    return request;
}
#endif