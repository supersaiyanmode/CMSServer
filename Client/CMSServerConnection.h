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

struct ACKWaiter {
    Mutex* mutex;
    Condition* condition;
};

struct CMSMessageSendData {
    GenericCMSMessage message;
    Time originalSentTime;
    Time lastSentTime;
    UniqueID id;
};

class CMSServerConnection {
    //General Stuff
    bool connectionActive;
    Connection conn;
    std::map<UniqueID, CMSClient*> clients;
    Mutex *clientsMapLock;
    bool closed;
    
    
    //Incoming stuff
    bool readerThreadActive;
    Thread<CMSServerConnection, int> *readerThread;
    
    
    //Outgoing stuff
    Mutex *writeLock;
    
    
    //Resend stuff
    /* not using a map, vector instead. Erase all the items before last received ACK */
    std::vector<CMSMessageSendData> sentData; 
    Mutex *sentDataLock;
    bool resendThreadActive;
    Thread<CMSServerConnection, int> *resendThread;
    
    
    //Wait stuff
    std::map<UniqueID, ACKWaiter> waiters;
    Mutex *waitersLock;
    
    
    
    CMSServerConnection(const std::string&, int);
    ~CMSServerConnection();
    
    bool doRegister(CMSClient*, bool);
    void resendProcess(int);
    
    bool write_(GenericCMSMessage&, bool);
public:
    static CMSServerConnection* createCMSServerConnection(const std::string&, int);
    
    bool readable() const;
    bool writable() const;
    
    UniqueID write(GenericCMSMessage&);
    bool writeWithAck(GenericCMSMessage&);
    
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