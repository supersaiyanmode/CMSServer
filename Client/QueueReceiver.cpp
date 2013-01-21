#include "QueueReceiver.h"
#include "../Util/Regex/RegexMatcher.h"
#include "../Util/Thread/ThreadLogger.h"

namespace {
    RegexMatcher queueDestinationRE("^[A-Za-z]+$");
}



QueueReceiver::QueueReceiver(CMSServerConnection& c, const std::string& d):
                    conn(c), cmsDestination(d){
    if (!queueDestinationRE.search(cmsDestination))
        throw "Not a valid Queue name";
    
    tlog("Registering QueueReceiver..");
    conn.registerClient(this);
    tlog("Registration done!");
}

QueueReceiver::~QueueReceiver() {
    
}