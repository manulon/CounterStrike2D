#include "ClientProtocol.h"

ClientProtocol::ClientProtocol( BlockingQueue<std::shared_ptr<ClientMessage>>& queue):
 queue(queue){}

ClientProtocol::~ClientProtocol(){}

void ClientProtocol::moveLeft(){
    char key(MOVE_LEFT);

    std::shared_ptr<Event> newEvent(new Event(1,key,-1));
    queue.push(newEvent);
}

void ClientProtocol::moveRight(){
    char key(MOVE_RIGHT);

    std::shared_ptr<Event> newEvent(new Event(1,key,-1));
    queue.push(newEvent);
}

void ClientProtocol::moveDown(){
    char key(MOVE_DOWN);

    std::shared_ptr<Event> newEvent(new Event(1,key,-1));
    queue.push(newEvent);
}

void ClientProtocol::moveUp(){
    char key(MOVE_UP);

    std::shared_ptr<Event> newEvent(new Event(1,key,-1));
    queue.push(newEvent);
}

void ClientProtocol::stopMoveLeft(){
    char key(STOP_LEFT);

    std::shared_ptr<Event> newEvent(new Event(1,key,-1));
    queue.push(newEvent);
}

void ClientProtocol::stopMoveRight(){
    char key(STOP_RIGHT);

    std::shared_ptr<Event> newEvent(new Event(1,key,-1));
    queue.push(newEvent);
}

void ClientProtocol::stopMoveDown(){
    char key(STOP_DOWN);

    std::shared_ptr<Event> newEvent(new Event(1,key,-1));
    queue.push(newEvent);
}

void ClientProtocol::stopMoveUp(){
    char key(STOP_UP);

    std::shared_ptr<Event> newEvent(new Event(1,key,-1));
    queue.push(newEvent);
}

void ClientProtocol::quit(){
    char key(QUIT);

    std::shared_ptr<Event> newEvent(new Event(1,key,-1));
    queue.push(newEvent);
    std::cout<<"Envio el quit "<<std::endl;
}

void ClientProtocol::attack(short angle) {
    char key(SHOOT);
    
    std::shared_ptr<Event> newEvent(new Event(1,key,angle-90));
    queue.push(newEvent);
}

void ClientProtocol::pickUpWeapon(){
    char key(PICK_UP_WEAPON);

    std::shared_ptr<Event> newEvent(new Event(1,key,-1));
    queue.push(newEvent);
}

void ClientProtocol::stopPickingUpWeapon(){
    char key(STOP_PICKING_UP_WEAPON);

    std::shared_ptr<Event> newEvent(new Event(1,key,-1));
    queue.push(newEvent);
}

/*
ClienteEvento
evento simple      evento shoot      evento bala
    id                                  posicion
                                        opcode

--------------------------------------------------------------------

ServidorEvento
evento simple      evento attack         evento shoot
    id player           id player           
    opcode              opcode

--------------------------------------------------------------------

Por cada cliente aceptado en el socket aceptador, hay dos hilos ... sender y receiver.

Habra una cola no bloqueante que sera referencia de todos los hilos receiver. Y es del server

Habra una cola bloqueante por cada hilo sender.

class Server{ std::vector<ServerClient> vector }

class ThreadAcceptor { std::vector<ServerClient>& vector }

class ServerClient{ ThreadSender sender;
                    ThreadReceiver& receiver; }

class ThreadSender{ std::queue<ServerMessage> queue }

class ThreadReceiver{ std::queue<ServerEvent>& queue }

class ClientMessage{    char opcode;
                        int arg;
                        int playerId;
                    }
                        
class ServerMessage{    char opcode;    //0 mando los ServerObject y 1 es un log para imprimir.
                        Entity& entity;
                        std::string message;
                    }

El servidor va a ser el que instancie al thread acceptor y tenga como atributo a la queue
eventhandler.

class Server{   EventHandler ev;

                run(){
                    creo aca el thread acceptor.
                    creo la cola noblocke
                    corro el thread aceptador --- delego.
                    joineo el hilo aceptador
                }
                todo esto va a andar hasta que se termine el juego   
             
| mover(1) | mover(1) | mover(2) | girar(1) | desparar(2) | | | 


en el event handler..... 
handleEvent(queue& receiver){
    for( auto& event: receiver){
        if ( event.getOpcode == MOVER_IZQUIERDA )
            world.moverizq(event.getPlayerId());

        if ( event.getOpcode == EXPLOTA_BOMBA)
            world.explotarBomba();
    }
}

MANDAR TODO EL TIEMPO LA POSICION DE TODAS LAS BALAS Y DE TODAS LAS ARMAS

for ( cliente in clientes){
    for( evento in eventos)
        cliente.agregarACola(evento)
}

*/
