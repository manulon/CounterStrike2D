#ifndef _THREAD_CLIENT_SENDER_
#define _THREAD_CLIENT_SENDER_

#include "Thread.h"
#include "Socket.h"
#include "BlockingQueue.h"
#include "Event.h"
#include "CommunicationProtocol.h"
#include "ProtocolConstants.h"

class ThreadClientSender : public Thread {
    private:
        Socket &skt;
        BlockingQueue<std::shared_ptr<ClientMessage>> &queue;
        int id;
        bool isRunning;

    public:
        ThreadClientSender
        (Socket &skt, BlockingQueue<std::shared_ptr<ClientMessage>> &queue, int id):
        skt(skt), queue(queue), id(id), isRunning(true){}
        
        ~ThreadClientSender(){}
        
        virtual void run(){
            CommunicationProtocol protocol(skt);
            while(isRunning){
                try{
                    std::cout << "Antes del pop\n";
                    std::shared_ptr<ClientMessage> event = queue.pop();
                    std::cout << "Despues del pop\n";
                    isRunning = event->send(protocol); 
                    std::cout << "Despues del send\n";

                } catch (const std::exception &){
                    isRunning = false;
                    break;
                }
            }  
        }      
};

#endif