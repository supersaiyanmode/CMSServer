#include "QueueReceiver.h"
#include "../Util/Thread/ThreadLogger.h"



QueueReceiver::QueueReceiver(CMSServerConnection& c, const CMSDestGroup& d):
                    conn(c), cmsDestGroup(d){
    conn.registerClient(this);
}

QueueReceiver::~QueueReceiver() {
    
}