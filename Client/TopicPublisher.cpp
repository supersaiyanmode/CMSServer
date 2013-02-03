#include "TopicPublisher.h"
#include "../Util/Thread/ThreadLogger.h"

TopicPublisher::TopicPublisher(CMSServerConnection& c, const std::string& d) :
            conn(c), destination(d){
        
}

TopicPublisher::~TopicPublisher() {

}

bool TopicPublisher::publish(const CMSHeaderSet& custom, const std::string& message) {
    CMSHeaderSet standard;
    standard["direction"] = "forward";
    standard["category"] = GenericCMSMessage::CMSMessageTypeToStr(GenericCMSMessage::Topic);
    standard["destination"] = destination;
    GenericCMSMessage out(standard, custom, message);
    GenericCMSMessage ack;
    return conn.writeWithAck(out, ack);
}

bool TopicPublisher::publish(const std::string& message) {
    return publish(CMSHeaderSet(), message);
}