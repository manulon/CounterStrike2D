#include "ThreadServerSender.h"

ThreadServerSender::ThreadServerSender(Socket &skt, std::shared_ptr<BlockingQueue<ServerMessage*>> queue) : 
                    skt(skt), queue(queue), isRunning(true){}

void ThreadServerSender::run(){
    CommunicationProtocol protocol(skt);
    while(isRunning){
        try{
            ServerMessage* msg = queue->pop(); //se bloquea aca
            msg->send(protocol);
            delete msg;
        } catch (const std::exception &e){
            isRunning = false;
        }
    }
}

bool ThreadServerSender::isDead(){
    return !isRunning;
}

void ThreadServerSender::stop(){
    queue->close();
}
