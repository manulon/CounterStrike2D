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
        skt(skt), queue(queue), id(id), isRunning(false){}
        
        ~ThreadClientSender(){}
        
        virtual void run(){
            isRunning = true;
            CommunicationProtocol protocol(skt);
            while(isRunning){
                try{
                    std::shared_ptr<Event> newEvent = queue.pop(); //se bloquea aca
                    protocol.send_int16(newEvent->getId()); //envio el id del player

                    char opcode(newEvent->getOpcode());
                    protocol.send_message(&opcode,1); //envio el opcode del player
                    
                    //if ( newEvent->getArg() != NULL )
                    //    protocol.send_int16(newEvent->getArg()); //envio el arg del player

                    if ( opcode == SHOOT )
                        protocol.send_int16(newEvent->getArg()); //envio el arg del player


                } catch (const std::exception &){
                    isRunning = false;
                    break;
                }
            }
        }
};

#endif