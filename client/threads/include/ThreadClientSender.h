#ifndef _THREAD_CLIENT_SENDER_
#define _THREAD_CLIENT_SENDER_

#include "Thread.h"
#include "Socket.h"
#include "BlockingQueue.h"
#include "../common/Event.h"
#include "CommunicationProtocol.h"
#include "ProtocolConstants.h"

class ThreadClientSender : public Thread {
    private:
        Socket &skt;
        BlockingQueue<std::shared_ptr<Event>> &queue;
        int id;
        bool isRunning;

    public:
        ThreadClientSender
        (Socket &skt, BlockingQueue<std::shared_ptr<Event>> &queue, int id):
        skt(skt), queue(queue), id(id), isRunning(true){}
        
        ~ThreadClientSender(){}
        
        virtual void run(){
            isRunning = true;
            CommunicationProtocol protocol(skt);
            while(isRunning){
                try{
                    std::shared_ptr<Event> newEvent = queue.pop();
                    protocol.send_int16(newEvent->getId());

                    char opcode(newEvent->getOpcode());
                    protocol.send_message(&opcode,1);                

                    if ( opcode == SHOOT )
                        protocol.send_int16(newEvent->getArg());  //envio el arg del player

                    if ( opcode == QUIT )                         // esto deberia quedarse asi???
                        isRunning = false;

                } catch (const std::exception &){
                    isRunning = false;
                    break;
                }
            }  
        }      
};

#endif