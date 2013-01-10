#include "Connection.h"
#include "TCPServerSocket.h"
#include "TCPClientSocket.h"

Connection::Connection(TCPSocket s): socket(s) {
    sockaddr_in remote,local;
    socklen_t remoteLen = sizeof(remote), localLen = sizeof(local);
    
    PLATFORM_SOCKET sock = (PLATFORM_SOCKET)s;
    
    //Local
    int localPort;
    char localStr[128];
    ::getsockname(sock, (sockaddr*)&local, &localLen);
    ::inet_ntop(AF_INET, &local.sin_addr.s_addr, localStr, 128);
    localPort = htons(local.sin_port);
    localEndPoint = std::make_pair(localStr, localPort);
    
    //remote
    int remotePort;
    char remoteStr[128];
    ::getpeername(sock, (sockaddr*)&remote, &remoteLen);
    ::inet_ntop(AF_INET, &remote.sin_addr.s_addr, remoteStr, 128);
    remotePort = ntohs(remote.sin_port);
    remoteEndPoint = std::make_pair(remoteStr, remotePort);
}

Connection::Connection(): socket(1,0,0){
    
}

Connection::~Connection() {
    
}

std::pair<std::string, int> Connection::getLocalAddress() {
    return localEndPoint;
}
std::pair<std::string, int> Connection::getRemoteAddress(){
    return remoteEndPoint;
}

Connection Connection::open(const std::string& remoteStr, int port){
    TCPClientSocket socket(remoteStr, port);
    socket.initialise();
    return socket;
}

int Connection::write(const char* buf, int len){
    return socket.write(buf, len);
}

int Connection::write(const std::vector<char>& v){
    return socket.write(v);
}

int Connection::write(const std::string& s){
    return socket.write(s);
}

int Connection::read(char* buf, int len){
    return socket.read(buf, len);
}

int Connection::read(std::vector<char>& v, int len){
    return socket.read(v,len);
}

int Connection::read(std::string& s, int len){
    return socket.read(s,len);
}

int Connection::closeReading(){
    return socket.closeReading();
}

int Connection::closeWriting(){
    return socket.closeWriting();
}
int Connection::close(){
    return socket.close();
}