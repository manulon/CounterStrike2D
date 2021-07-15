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
        BlockingQueue<std::shared_ptr<ClientMessage>> &queue;
        int id;
        bool isRunning;

    public:
        ThreadClientSender
        (Socket &skt, BlockingQueue<std::shared_ptr<ClientMessage>> &queue, int id):
        skt(skt), queue(queue), id(id), isRunning(true){}
        
        ~ThreadClientSender(){}
        
        virtual void run(){
            isRunning = true;
            CommunicationProtocol protocol(skt);
            while(isRunning){
                try{
                    std::shared_ptr<ClientMessage> event = queue.pop();
                    isRunning = event->send(protocol); 

                } catch (const std::exception &){
                    isRunning = false;
                    break;
                }
            }  
        }      
};

#endif