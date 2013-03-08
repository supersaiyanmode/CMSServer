#ifndef CMS_SERVER_CONNECTION_H
#define CMS_SERVER_CONNECTION_H

#include "../Protocol/CMSMessage/GenericCMSMessage.h"
#include "../Util/IO/SocketIO/Connection.h"
#include "../Util/Thread/Thread.h"
#include "../Util/Thread/Mutex.h"
#include "../Util/Thread/ReadWriteLock.h"
#include "../Util/Thread/ThreadLogger.h"
#include "../Util/Thread/Condition.h"
#include "../Util/Thread/SynchronisedQueue.h"
#include "../Util/Random/Sequential.h"
#include "CMSClient.h"

#include <map>

struct ACKWaiter { //TODO: GIve a sensible name
    bool result;
    GenericCMSMessage ackMsg;
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
    ReadWriteLock *clientsMapRWLock;
    bool closed;
    
    
    //Incoming stuff
    bool readerThreadActive;
    Thread<CMSServerConnection, int> *readerThread;
    
    
    //Outgoing stuff
    Mutex *writeLock;
    
    
    //Resend stuff
    /* not using a map, vector instead. Erase all the items before last received ACK */
    std::vector<CMSMessageSendData> sentData; 
    ReadWriteLock *sentDataRWLock;
    bool resendThreadActive;
    Thread<CMSServerConnection, int> *resendThread;
    
    
    //Wait stuff
    std::map<UniqueID, SynchronisedQueue<ACKWaiter>* > waiters;
    Mutex *waitersLock; //No need for RWLock here, plain mutex will do.
    
    
    
    CMSServerConnection(const std::string&, int);
    
    bool doRegister(CMSClient*, bool, GenericCMSMessage&);
    void resendProcess(int);
    
    bool write_(GenericCMSMessage&, bool);
public:
    ~CMSServerConnection();
    static CMSServerConnection* createCMSServerConnection(const std::string&, int);
    
    bool readable() const;
    bool writable() const;
    
    UniqueID write(GenericCMSMessage&);
    bool writeWithAck(GenericCMSMessage&, GenericCMSMessage&);
    
    void close();
    
    bool registerClient(CMSClient*);
    bool unregisterClient(CMSClient*);
    
    
    void processIncomingMessages(int);
};



/*

    TODO: Implement reader-writer lock
    implement lock for writeWithAck, ack msg write and read form Waiter Strucuture



*/



//INLINE FUNCTIONS
inline bool CMSServerConnection::writable() const {
    return conn.writable() && connectionActive;
}

inline bool CMSServerConnection::readable() const {
    return conn.readable() && connectionActive;
}

inline CMSServerConnection* CMSServerConnection::createCMSServerConnection(
        const std::string& a, int b){
    return new CMSServerConnection(a,b);
}


#endif