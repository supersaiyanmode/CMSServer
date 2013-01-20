#include "ClientEndPoint.h"

ClientEndPoint::ClientEndPoint(Connection& c, MessageProcessor& mp): 
                active(true), conn(c), MessageProcessor(mp) {
    mp.registerEndPoint(*this);
    queue = SynchronisedQueue<GenericCMSMessage>::createSynchronisedQueue();
    outThread = Thread<ClientEndPoint, int>::createThread(this, &ClientEndPoint::processOutgoing);
    outThread->start(0);
}

ClientEndPoint::~ClientEndPoint(){
    active = false;
    conn.close();
    outThread->join();
    delete outThread;
    delete queue;
    mp.unregisterEndPoint(*this);
}

void ClientEndPoint::processOutgoing(){
    while (active && conn.writable() && *queue) {
        GenericCMSMessage msg;
        if (!queue->timedPop(msg, 50000))
            continue;
        if (conn.write(msg.str()) <= 0){
            conn.closeWriting();
            break;
        }
    }
}

void ClientEndPoint::processIncoming(){
    while (active && conn.readable()) {
        GenericCMSMessage msg;
        if (!GenericCMSMessage::parse(conn, msg)) {
            std::cout<<"Invalid CMS Message!!\n";
            continue;
        }
        
        //Register Session
        //Send back acknowledgement
        
        if (msg.isForward()) {
            CMSHeaderSet chs;
            switch (msg.category()) {
                case GenericCMSMessage::Queue: {
                    mp.registerQueue();
                }
                
                case GenericCMSMessage::Topic: {
                    mp.registerTopic();
                }
                
                case GenericCMSMessage::Register: {
                    mp.registerClient();
                }
                
                case GenericCMSMessage::UnRegister: {
                    mp.unregisterClient();
                }
            }
        } else { //implicit that its backward (ACK), GenericCMSMessage::parse(..) must validate value too - TODO!
            
        }
        std::cout<<"Got:\n"<<msg.str()<<std::endl;
    }
    conn.closeReading();
}