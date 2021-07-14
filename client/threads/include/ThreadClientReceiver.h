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
        NonBlockingQueue<const char*>& queue;
        bool isRunning;
        
    public:
        ThreadClientReceiver(Socket &skt, NonBlockingQueue<const char*>& queue):
        skt(skt), queue(queue), isRunning(true){}

        ~ThreadClientReceiver(){}

        virtual void run(){
            CommunicationProtocol protocol(skt);
            while(isRunning){
                try{
                    char messageType;
                    std::cout <<"antes de recibir el primer mensaje\n";
                    ssize_t received = protocol.receive_message(1,&messageType);
                    if (received == 0){
                        isRunning = false;
                        queue.push("exit");
                        break;
                    }
                    std::cout <<"despues de recibir el primer mensaje\n";
                    // if es tal tipo de mesnaje bla bla
                    int length(protocol.receive_size());
                    std::vector<char> buffer(length);
                    received = protocol.receive_message(length, buffer.data());
                    std::cout <<"se recibioeron"<< received<<std::endl;
                    queue.push(buffer.data());
                } catch (const std::exception& e){
                    queue.push("exit");
                    isRunning = false;
                    break;
                }
                
            }
        }
};

#endif
