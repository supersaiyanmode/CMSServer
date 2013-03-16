#include "TopicSubscriber.h"
#include "../Util/Thread/ThreadLogger.h"



TopicSubscriber::TopicSubscriber(CMSServerConnection& c, const CMSDestGroup& d):
                    conn(c), cmsDestGroup(d){
    conn.registerClient(this);
}

TopicSubscriber::~TopicSubscriber() {
    
}