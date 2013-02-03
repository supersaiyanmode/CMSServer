#include "TopicSubscriber.h"
#include "../Util/Thread/ThreadLogger.h"



TopicSubscriber::TopicSubscriber(CMSServerConnection& c, const std::string& d):
                    conn(c), cmsDestination(d){
    conn.registerClient(this);
}

TopicSubscriber::~TopicSubscriber() {
    
}