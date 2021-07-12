#include "ThreadServerReceiver.h"

ThreadServerReceiver::ThreadServerReceiver(Socket &skt, NonBlockingQueue<std::shared_ptr<Event>> &queue):
skt(skt), queue(queue), isRunning(false){}

void ThreadServerReceiver::run(){
    isRunning = true;
    CommunicationProtocol protocol(skt);
    while(isRunning){
        try{
            std::cout<<std::endl<<"-----------------------"<<std::endl;
            int arg = 0;
            int id = protocol.receive_size();
            std::cout<<"Del jugador de "<<id<<" recibi";
            char buffer;
            protocol.receive_message(1, &buffer);
            std::cout<<" la accion de "<<(int)buffer;
            if (buffer == SHOOT){     /*aca va a tener que ser otra cosa ¿enviar -1?*/
                arg = protocol.receive_size();
                std::cout<<" con argumento "<<arg;
            }
            std::shared_ptr<Event> event(new Event(id, buffer,arg));
            queue.push(event);
        } catch (const std::exception& e){
            isRunning = false;
            break;
        }
        
    }
}
