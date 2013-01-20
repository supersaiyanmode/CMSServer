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
}

QueueSender::~QueueSender() {
    conn.unregisterClient(this);
    delete sendLock;
}

bool QueueSender::send(const CMSHeaderSet& custom, const std::string& message) {
    CMSHeaderSet standard;
    standard["receiver-id"] = CMSClient::id();
    standard["direction"] = "forward";
    standard["category"] = GenericCMSMessage::CMSMessageTypeToStr(GenericCMSMessage::Queue);
    GenericCMSMessage out(standard, custom, message);
    
    return conn.writeWithAck(out);
}

bool QueueSender::send(const std::string& message) {
    return send(CMSHeaderSet(), message);
}