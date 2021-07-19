#include "ThreadServerReceiver.h"
#include <unistd.h>
#include "PlayerMovementEvent.h"
#include "QuitEvent.h"
#include "ShootEvent.h"
#include "LoginEvent.h"
#include "PickUpWeaponEvent.h"
#include "StopPickingUpWeaponEvent.h"
#include "UpdateAngleEvent.h"

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
                std::cout<<"JOIN EVENT\n";
                short len  = protocol.receive_size();
                std::vector<char> buffer(len);
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


// std::cout<<std::endl<<"-----------------------"<<std::endl;
            // int arg = 0;
            // std::cout<<"Waiting for receive size "<<std::endl;
            // int id(protocol.receive_size());
            // std::cout<<"Del jugador de "<<id<<" recibi"<<std::endl;
            // char buffer;
            // protocol.receive_message(1, &buffer);
            // std::cout<<" la accion "<<(int)buffer<<std::endl;
            // if (buffer == SHOOT) {     aca va a tener que ser otra cosa ¿enviar -1?
                // arg = protocol.receive_size();
                // std::cout<<" con argumento "<<arg<<std::endl;
            // }
// 
            // if (buffer == QUIT) {
                // isRunning = false;
                // skt.close();
            // }
// 
// 
bool ThreadServerReceiver::isMovementMessage(char opcode){
    return (opcode >= MOVE_LEFT && opcode <= STOP_DOWN);
}