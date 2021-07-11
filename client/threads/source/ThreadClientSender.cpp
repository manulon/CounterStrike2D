#include "ThreadClientSender.h"

ThreadClientSender::ThreadClientSender
(Socket &skt, std::shared_ptr<BlockingQueue<Event>> &queue, int id): 
skt(skt), queue(queue), id(id), isRunning(false){}

void ThreadClientSender::run(){
    isRunning = true;
    CommunicationProtocol protocol(skt);
    while(isRunning){
        try{
            Event newEvent = queue->pop(); //se bloquea aca
            protocol.send_int16(newEvent.getId()); //envio el id del player

            std::vector<char> opcode(newEvent.getOpcode(),0);
            protocol.send_message(opcode.data(),1); //envio el opcode del player
            
            if ( newEvent.getArg() != NULL )
                protocol.send_int16(newEvent.getArg()); //envio el arg del player

        } catch (const std::exception &){
            isRunning = false;
            break;
        }
    }
}