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
#include "JoinOtherPlayerInfo.h"
#include "JoinInfo.h"
#include "BulletInfo.h"
#include "WeaponInfo.h"
#include "DeadPlayerInfo.h"
#include "EndOfGameInfo.h"
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
                    ssize_t received = protocol.receive_message(1,&messageType);
                    if (received == 0 ){
                        isRunning = false;
                        break;
                    }
                    std::shared_ptr<Info> info = nullptr;
                    if (messageType == LIFE_MESSAGE){
                        std::shared_ptr<Info> aux(new LifeInfo(protocol.receive_size()));
                        info = aux;
                    } else if (messageType == PLAYER_INFO){
                        std::shared_ptr<Info> aux(
                            new PlayerInfo(
                                protocol.receive_size(), protocol.receive_float(),
                                protocol.receive_float(),protocol.receive_size(),
                                protocol.receive_size())
                        );
                        info = aux;
                    } else if (messageType == OTHER_PLAYER_JOIN){
                        std::shared_ptr<Info> aux(new JoinOtherPlayerInfo((short)protocol.receive_size()));
                        info = aux;
                    } else if (messageType == JOIN){
                        std::shared_ptr<Info> aux(new JoinInfo((short)protocol.receive_size()));
                        info = aux;
                    } else if (messageType == BULLET_MESSAGE){
                        float x = protocol.receive_float();
                        float y = protocol.receive_float();//pushear info bullet
                        std::shared_ptr<Info> aux(new BulletInfo(x,y));
                        info = aux;
                    } else if (messageType == WEAPON_MESSAGE){
                        short id = protocol.receive_size();
                        float x = protocol.receive_float();
                        float y = protocol.receive_float(); //pushear info bullet
                        std::shared_ptr<Info> aux(new WeaponInfo(id,x,y));
                        info = aux;
                    } else if (messageType == DEAD_PLAYER){
                        std::shared_ptr<DeadPlayerInfo> aux(new DeadPlayerInfo(protocol.receive_size()));
                        info = aux;
                    } else if (messageType == TEXT_MESSAGE){
                        short len = protocol.receive_size();
                        std::vector<char> buffer(len + 1,'\0');
                        protocol.receive_message(len,buffer.data());
                        std::string message(buffer.data());
                        std::shared_ptr<Info> aux(new EndOfGameInfo(std::move(message)));
                        info = aux;
                    }

                    queue.push(info);
                } catch (const std::exception& e){
                    isRunning = false;
                    break;
                }
                
            }
        }
};

#endif
