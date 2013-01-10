#include "SocketException.h"

SocketException::SocketException(const std::string& str):msg(str){
    
}
const char* SocketException::what() const throw(){
    return ("SocketException: " + msg).c_str();
}

SocketException::~SocketException() throw(){
    
}