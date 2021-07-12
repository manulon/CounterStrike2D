#include "ThreadServerReceiver.h"

ThreadServerReceiver::ThreadServerReceiver(Socket &skt, NonBlockingQueue<std::shared_ptr<Event>> &queue):
skt(skt), queue(queue), isRunning(false){}

void ThreadServerReceiver::run(){
    isRunning = true;
    CommunicationProtocol protocol(skt);
    while(isRunning){
        try{
            int arg = 0;
            int id = protocol.receive_size();
            std::cout<<"Recibi la del jugador de id "<<id;
            char buffer;
            protocol.receive_message(1, &buffer);
            std::cout<<" la accion de "<<(int)buffer;
            if (buffer == SHOOT){     /*aca va a tener que ser otra cosa ¿enviar -1?*/
                arg = protocol.receive_size();
                std::cout<<" con argumento"<<arg;
            }
            std::shared_ptr<Event> event(new Event(id, buffer,arg));
            queue.push(event);
            std::cout<<std::endl<<"-----------------------"<<std::endl;

        } catch (const std::exception& e){
            isRunning = false;
            break;
        }
        
    }
}
