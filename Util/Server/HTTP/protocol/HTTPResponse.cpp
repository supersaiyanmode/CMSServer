#include "HTTPResponse.h"
#include "../../../DataType/Primitive/Number.h"

const std::string HTTPResponse::m_version = "HTTP/1.0";

HTTPResponse::HTTPResponse(): m_statusCode(200), m_phrase("OK"), m_valid(true) {}

HTTPResponse::HTTPResponse(int code, const std::string& phrase):
        m_statusCode(code), m_phrase(phrase), m_valid(true) {
    
}

void HTTPResponse::setContentType(const std::string& mime) {
    m_headers["Content-Type"] = mime;
}

void HTTPResponse::write(const std::string& str) {
    m_body = str;
    m_headers["Content-Length"] = Number(m_body.length()).str();
    
    if (m_headers.find("Content-Type") == m_headers.end()) {
        setContentType("text/plain");
    }
}

std::string HTTPResponse::str() {
    std::string CRLF = "\r\n";
    std::string result = m_version + " " + Number(m_statusCode).str() + " " + m_phrase + CRLF;
    for (std::map<std::string, std::string>::const_iterator it=m_headers.begin(); it!=m_headers.end(); it++) {
        result += it->first + ": " + it->second + CRLF;
    }
    result += CRLF;
    
    if (m_body.length() > 0) {
        result += m_body;
    }
    return result;
}