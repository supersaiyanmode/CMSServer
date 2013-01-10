#ifndef SOCKET_EXCEPTION_H
#define SOCKET_EXCEPTION_H
#include <exception>
#include <string>
class SocketException: public std::exception {
    std::string msg;
public:
    SocketException(const std::string&);
    virtual const char* what() const throw();
    ~SocketException() throw();
};
#endif