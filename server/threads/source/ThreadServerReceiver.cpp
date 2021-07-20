#include "ThreadServerReceiver.h"
#include <unistd.h>
#include "PlayerMovementEvent.h"
#include "QuitEvent.h"
#include "ShootEvent.h"
#include "LoginEvent.h"
#include "PickUpWeaponEvent.h"
#include "StopPickingUpWeaponEvent.h"
#include "UpdateAngleEvent.h"
#include "SwitchWeaponEvent.h"
ThreadServerReceiver::ThreadServerReceiver(Socket &skt, 
    NonBlockingQueue<std::shared_ptr<ServerEvent>>& queue, 
    short clientID) :
    skt(skt), queue(queue), isRunning(true), clientID {clientID} { }

void ThreadServerReceiver::run(){
    CommunicationProtocol protocol(skt);
    while (isRunning) {
        try{
            char buffer;
            ssize_t received = protocol.receive_message(1, &buffer);
            if (received == 0) {
                isRunning = false;
                break; 
            }
            std::shared_ptr<ServerEvent> event(nullptr);
            
            if (isMovementMessage(buffer)){
                std::shared_ptr<ServerEvent> aux(new PlayerMovementEvent(clientID, buffer));
                event = aux;
            } else if (buffer == SHOOT) { 
                int arg = protocol.receive_size();
                std::shared_ptr<ServerEvent> aux(new ShootEvent(clientID, arg));
                event = aux;
            } else if (buffer == JOIN){
                short len  = protocol.receive_size();
                std::vector<char> buffer(len + 1,'\0');
                protocol.receive_message(len,buffer.data());
                std::string mapName(buffer.data());
                std::shared_ptr<ServerEvent> aux(new LoginEvent(clientID,std::move(mapName)));
                event = aux;
            } else if (buffer == QUIT) {
                isRunning = false;
                skt.close();
                std::shared_ptr<ServerEvent> aux(new QuitEvent(clientID));
                event = aux;

            } else if (buffer == PICK_UP_WEAPON){
                std::shared_ptr<ServerEvent> aux(new PickUpWeaponEvent(clientID));
                event = aux;
            } else if (buffer == STOP_PICKING_UP_WEAPON){
                std::shared_ptr<ServerEvent> aux(new StopPickingUpWeaponEvent(clientID));
                event = aux;
            } else if (buffer == ANGLE){
                short arg(protocol.receive_size());
                std::shared_ptr<ServerEvent> aux(new UpdateAngleEvent(clientID,arg));
                event = aux;
            } else if (buffer == SWITCH_WEAPON){
                protocol.receive_message(1, &buffer);
                std::shared_ptr<ServerEvent> aux(new SwitchWeaponEvent(clientID, buffer));
                event = aux;
            }
            queue.push(event);

        } catch (const std::exception& e){
            isRunning = false;
            break;
        }
    }
}

bool ThreadServerReceiver::isDead(){
    return !isRunning;
}

bool ThreadServerReceiver::isMovementMessage(char opcode){
    return (opcode >= MOVE_LEFT && opcode <= STOP_DOWN);
}