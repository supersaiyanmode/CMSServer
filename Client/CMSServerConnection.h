#ifndef CMS_SERVER_CONNECTION_H
#define CMS_SERVER_CONNECTION_H

#include "../Protocol/CMSMessage/GenericCMSMessage.h"
#include "../Util/IO/SocketIO/Connection.h"
#include "../Util/Thread/Thread.h"
#include "../Util/Thread/Mutex.h"
#include "../Util/Thread/Condition.h"
#include "../Util/Random/Sequential.h"
#include "CMSClient.h"

#include <map>

class CMSServerConnection {
    bool readerThreadActive, connectionActive;
    Connection conn;
    
    std::map<UniqueID, CMSClient*> clients;
    
    std::map<UniqueID, GenericCMSMessage> pendingAcknowledgements;
    std::map<UniqueID, Condition*> pendingRegistrationsConditions;
    std::map<UniqueID, Mutex*> pendingRegistrationsMutexes;
    
    Thread<CMSServerConnection, int>* readerThread;
    Mutex *writeLock, *pendingAcknowledgementsMapLock, *clientsMapLock;
    
    
    CMSServerConnection(const std::string&, int);
    ~CMSServerConnection();
    
    bool doRegister(CMSClient*, bool);
public:
    static CMSServerConnection* createCMSServerConnection(const std::string&, int);
    
    bool readable() const;
    bool writable() const;
    
    UniqueID write(GenericCMSMessage&);
    
    void close();
    
    bool registerClient(CMSClient*);
    bool unregisterClient(CMSClient*);
    
    
    void processIncomingMessages(int);
};




//INLINE FUNCTIONS
inline bool CMSServerConnection::writable() const {
    return conn.writable() && connectionActive;
}

inline bool CMSServerConnection::readable() const {
    return conn.readable() && connectionActive;
}


inline bool CMSServerConnection::registerClient(CMSClient* receiver) {
    return doRegister(receiver, true);
}

inline bool CMSServerConnection::unregisterClient(CMSClient* receiver) {
    return doRegister(receiver, false);
}


#endif