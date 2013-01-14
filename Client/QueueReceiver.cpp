#include "QueueReceiver.h"
#include "../Util/Regex/RegexMatcher.h"
#include "../Util/Thread/ThreadLogger.h"

namespace {
    RegexMatcher queueDestinationRE("^([a-zA-Z][a-zA-Z0-9]*\\.)*(([a-zA-Z][a-zA-Z0-9]*)|>)$");
}



QueueReceiver::QueueReceiver(CMSServerConnection& c, const std::string& d):
                    conn(c), destination(d){
    if (!queueDestinationRE.search(destination))
        throw "Not a valid Queue name";
    
    tlog("Registering QueueSender..");
    conn.registerClient(this);
    tlog("Registration done!");
}

QueueReceiver::~QueueReceiver() {
    
}