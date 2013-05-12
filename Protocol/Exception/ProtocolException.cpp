#include "ProtocolException.h"

ProtocolException::ProtocolException(const std::string& s): msg(s) {
    
}

ProtocolException::~ProtocolException() throw() {
    
}
    
const char* ProtocolException::what() const throw() {
    return ("ProtocolException: " + msg).c_str();
};