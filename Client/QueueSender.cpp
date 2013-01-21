#include "QueueSender.h"
#include "../Util/Regex/RegexMatcher.h"
#include "../Util/Thread/ThreadLogger.h"

namespace {
    RegexMatcher queueDestinationRE("^[A-Za-z]+$");
}

QueueSender::QueueSender(CMSServerConnection& c, const std::string& d) :
            conn(c), destination(d){
    
    if (!queueDestinationRE.search(d)){
        tlog("Error: Not a valid queue name!");
        throw "Not a valid Queue name";
    }
    
}

QueueSender::~QueueSender() {

}

bool QueueSender::send(const CMSHeaderSet& custom, const std::string& message) {
    CMSHeaderSet standard;
    standard["direction"] = "forward";
    standard["category"] = GenericCMSMessage::CMSMessageTypeToStr(GenericCMSMessage::Queue);
    GenericCMSMessage out(standard, custom, message);
    
    return conn.writeWithAck(out);
}

bool QueueSender::send(const std::string& message) {
    return send(CMSHeaderSet(), message);
}