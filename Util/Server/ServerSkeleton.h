#ifndef SERVER_SKELETON_H
#define SERVER_SKELETON_H

#include "../IO/SocketIO/TCPServerSocket.h"

class ServerSkeleton {
protected:
    TCPServerSocket serverSocket;
public:
    ServerSkeleton(int);
    ServerSkeleton(const ServerSkeleton&);
    ServerSkeleton& operator=(const ServerSkeleton& other);
    
    virtual ~ServerSkeleton();
    
    virtual void initialise();

    Connection accept();
    void shutdown();
};



//INLINE FUNCTIONS
inline Connection ServerSkeleton::accept(){
    return serverSocket.accept();
}

inline void ServerSkeleton::shutdown(){
    serverSocket.close();
}

#endif