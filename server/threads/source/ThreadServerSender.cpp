#include "ThreadServerSender.h"

ThreadServerSender::ThreadServerSender(Socket &skt, BlockingQueue<ServerMessage*>* queue) : 
                    skt(skt), queue(queue), isRunning(true){}

void ThreadServerSender::run(){
    CommunicationProtocol protocol(skt);
    while(isRunning){
        try{
            ServerMessage* msg = queue->pop(); //se bloquea aca
            msg->send(protocol);
            delete msg;
        } catch (const std::exception &){
            isRunning = false;
            break;
        }
    }
}

bool ThreadServerSender::isDead(){
    return !isRunning;
}

