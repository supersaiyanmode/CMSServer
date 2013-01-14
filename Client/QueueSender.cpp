#include "QueueSender.h"
#include "../Util/Regex/RegexMatcher.h"
#include "../Util/Thread/ThreadLogger.h"

namespace {
    RegexMatcher queueDestinationRE("^([a-zA-Z][a-zA-Z0-9]*\\.)*(([a-zA-Z][a-zA-Z0-9]*)|>)$");
}

QueueSender::QueueSender(CMSServerConnection& c, const std::string& d) :
            conn(c), destination(d){
    
    if (!queueDestinationRE.search(d))
        throw "Not a valid Queue name";
    
    sendLock = Mutex::createMutex();
    ackLock = Mutex::createMutex();
    ackArrived = Condition::createCondition(ackLock);
    tlog("Registering QueueSender..");
    conn.registerClient(this);
    tlog("Registration done!");
}

QueueSender::~QueueSender() {
    conn.unregisterClient(this);
    delete sendLock;
    delete ackLock;
    delete ackArrived;
}

bool QueueSender::send(const CMSHeaderSet& custom, const std::string& message) {
    sendLock->acquire();
    CMSHeaderSet standard;
    standard["receiver-id"] = CMSClient::id();
    standard["direction"] = "forward";
    standard["category"] = GenericCMSMessage::CMSMessageTypeToStr(GenericCMSMessage::Queue);
    GenericCMSMessage out(standard, custom, message);
    
    waitStatus = -1;
    UniqueID waitID = conn.write(out);
    ackLock->acquire();
    ackArrived->wait();
    ackLock->release();
    sendLock->release();
    return waitStatus == 1;
}

bool QueueSender::send(const std::string& message) {
    return send(CMSHeaderSet(), message);
}

void QueueSender::onAcknowledgement(UniqueID id, GenericCMSMessage& msg){
    if (id == waitID){
        waitStatus = 1;
        response = msg;
        ackLock->release();
    } else {
        tlog("We just received a stray acknowledgement!");
    }
}

void QueueSender::onError(UniqueID id, GenericCMSMessage& msg) {
    if (id == waitID){
        waitStatus = 0;
        response = msg;
        ackLock->release();
    } else {
        tlog("A stray ack, with an error!");
    }
}

void QueueSender::onMessage(GenericCMSMessage& msg){
    
}