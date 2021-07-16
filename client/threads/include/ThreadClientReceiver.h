#ifndef _THREAD_CLIENT_RECEIVER_
#define _THREAD_CLIENT_RECEIVER_

#include "Thread.h"
#include "Socket.h"
#include "NonBlockingQueue.h"
#include "Event.h"
#include "CommunicationProtocol.h"
#include "ProtocolConstants.h"
#include "LifeInfo.h"
#include "PlayerInfo.h"

class ThreadClientReceiver : public Thread {
    private:
        Socket& skt;
        NonBlockingQueue<std::shared_ptr<Info>>& queue;
        bool isRunning;
        
    public:
        ThreadClientReceiver(Socket &skt, NonBlockingQueue<std::shared_ptr<Info>>& queue):
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
                        // queue.push("exit");
                        break;
                    }
                    std::shared_ptr<Info> info = nullptr;
                    if (messageType == LIFE_MESSAGE){
                        std::shared_ptr<Info> aux(new LifeInfo(protocol.receive_size()));
                        info = aux;
                    } else if (messageType == PLAYER_INFO){
                        std::shared_ptr<Info> aux(new PlayerInfo(protocol.receive_size(), protocol.receive_float()))
                    }

                    queue.push(info);
                } catch (const std::exception& e){
                    // queue.push("exit");
                    isRunning = false;
                    break;
                }
                
            }
        }
};

#endif
