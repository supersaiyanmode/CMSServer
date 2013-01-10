#ifndef CONNECTION_H
#define CONNECTION_H

#include "../InputOutputCapable.h"
#include "TCPSocket.h"
#include <algorithm>

class Connection : public InputOutputCapable {
    TCPSocket socket;
    std::pair<std::string, int> localEndPoint, remoteEndPoint;    
public:
    Connection();
    Connection(TCPSocket);
    ~Connection();
    
    virtual int write(const char*, int);
    virtual int write(const std::vector<char>&);
    virtual int write(const std::string&);

    virtual int read(char*, int);
    virtual int read(std::vector<char>&, int=8192);
    virtual int read(std::string&, int=8192);
    
    virtual int closeReading();
    virtual int closeWriting();
    virtual int close();
    
    std::pair<std::string, int> getLocalAddress();
    std::pair<std::string, int> getRemoteAddress();
    
    static Connection open(const std::string&, int);
};

#endif