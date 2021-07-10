#include "ClientProtocol.h"

ClientProtocol::ClientProtocol():
protocol(){}

ClientProtocol::~ClientProtocol(){}

void ClientProtocol::moveLeft(){
    char key(KEYWORD_SCANDODE_LEFT);

    //this->protocol.sendPlayerId(id);
    this->protocol.send_message(&key,1);
}

void ClientProtocol::moveRight(){
    char key(KEYWORD_SCANDODE_RIGHT);

    //this->protocol.sendPlayerId(id);
    this->protocol.send_message(&key,1);
}

void ClientProtocol::moveDown(){
    char key(KEYWORD_SCANDODE_DOWN);

    //this->protocol.sendPlayerId(id);
    this->protocol.send_message(&key,1);
}

void ClientProtocol::moveUp(){
    char key(KEYWORD_SCANDODE_UP);

    //this->protocol.sendPlayerId(id);
    this->protocol.send_message(&key,1);
}

void ClientProtocol::stopMoveLeft(){
    char key(KEYWORD_KEYUP_LEFT);

    //this->protocol.sendPlayerId(id);
    this->protocol.send_message(&key,1);
}

void ClientProtocol::stopMoveRight(){
    char key(KEYWORD_KEYUP_RIGHT);

    //this->protocol.sendPlayerId(id);
    this->protocol.send_message(&key,1);
}

void ClientProtocol::stopMoveDown(){
    char key(KEYWORD_KEYUP_DOWN);

    //this->protocol.sendPlayerId(id);
    this->protocol.send_message(&key,1);
}

void ClientProtocol::stopMoveUp(){
    char key(KEYWORD_KEYUP_UP);

    //this->protocol.sendPlayerId(id);
    this->protocol.send_message(&key,1);
}

void ClientProtocol::quit(){
    char key(QUIT);

    //this->protocol.sendPlayerId(id);
    this->protocol.send_message(&key,1);
}

void ClientProtocol::mouseDown(){
    char key(MOUSE_DOWN);

    //this->protocol.sendPlayerId(id);
    this->protocol.send_message(&key,1);
    //send angulo
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

