#include "ThreadServerSender.h"

ThreadServerSender::ThreadServerSender(Socket &skt, std::shared_ptr<BlockingQueue<std::string>> &queue, int id) : 
                    skt(skt), queue(queue), id(id), isRunning(false){}

void ThreadServerSender::run(){
    isRunning = true;
    CommunicationProtocol protocol(skt);
    while(isRunning){
        try{
            std::string msg = queue->pop(); //se bloquea aca
            protocol.send_int16(msg.length());
            protocol.send_message(msg.c_str(), msg.length());

        } catch (const std::exception &){
            isRunning = false;
            break;
        }
    }
}