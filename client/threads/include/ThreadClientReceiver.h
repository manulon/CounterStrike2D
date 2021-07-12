#ifndef _THREAD_CLIENT_RECEIVER_
#define _THREAD_CLIENT_RECEIVER_

#include "Thread.h"
#include "Socket.h"
#include "NonBlockingQueue.h"
#include "../common/Event.h"
#include "CommunicationProtocol.h"
#include "ProtocolConstants.h"

class ThreadClientReceiver : public Thread {
    private:
        Socket& skt;
        NonBlockingQueue<std::string>& queue;
        bool isRunning;
        
    public:
        ThreadClientReceiver(Socket &skt, NonBlockingQueue<std::string>& queue):
        skt(skt), queue(queue), isRunning(false){}

        ~ThreadClientReceiver(){}

        virtual void run(){
            isRunning = true;
            CommunicationProtocol protocol(skt);
            while(isRunning){
                try{
                    int length(protocol.receive_size());
                    std::vector<char> buffer(length,0);
                    protocol.receive_message(length, buffer.data());

                    queue.push(std::move(buffer.data()));
                } catch (const std::exception& e){
                    isRunning = false;
                    break;
                }
                
            }
        }
};

#endif
