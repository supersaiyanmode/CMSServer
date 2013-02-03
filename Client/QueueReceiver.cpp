#include "QueueReceiver.h"
#include "../Util/Thread/ThreadLogger.h"



QueueReceiver::QueueReceiver(CMSServerConnection& c, const std::string& d):
                    conn(c), cmsDestination(d){
    conn.registerClient(this);
}

QueueReceiver::~QueueReceiver() {
    
}