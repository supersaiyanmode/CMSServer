#ifndef CONNECTION_H
#define CONNECTION_H

#include "../InputOutputCapable.h"
#include "SocketException.h" //Not required per se, but allows for "SocketException" to be caught without extra headers
#include "TCPSocket.h"
#include <algorithm>

class Connection : public InputOutputCapable {
    TCPSocket socket;
    std::pair<std::string, int> localEndPoint, remoteEndPoint;
    std::string localAddressStr_, remoteAddressStr_;
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
    
    bool readable() const;
    bool writable() const;
    
    std::pair<std::string, int> getLocalAddress() const;
    std::pair<std::string, int> getRemoteAddress() const;

    std::string localAddressStr() const;
    std::string remoteAddressStr() const;
    
    static Connection open(const std::string&, int);
};




//INLINE FUNCTIONS

inline std::pair<std::string, int> Connection::getLocalAddress() const{
    return localEndPoint;
}

inline std::pair<std::string, int> Connection::getRemoteAddress() const{
    return remoteEndPoint;
}

inline std::string Connection::localAddressStr() const {
    return localAddressStr_;
}

inline std::string Connection::remoteAddressStr() const{
    return remoteAddressStr_;
}

inline bool Connection::readable() const {
    return socket.readable();
}

inline bool Connection::writable() const {
    return socket.writable();
}


#endif