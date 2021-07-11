#include "ThreadServerReceiver.h"

ThreadServerReceiver::ThreadServerReceiver(Socket &skt, NonBlockingQueue<std::unique_ptr<ClientEvent>> &queue):
 skt(skt), queue(queue), isRunning(false){}

void ThreadServerReceiver::run(){
    isRunning = true;
    CommunicationProtocol protocol(skt);
    while(isRunning){
        try{
            int arg = 0;
            int id = protocol.receive_size();
            char buffer;
            protocol.receive_message(1, &buffer);
            if (buffer == SHOOT){
                arg = protocol.receive_size();
            }
            std::unique_ptr<ClientEvent> event(new ClientEvent(id, buffer,arg));
            queue.push(std::move(event));
        } catch (const std::exception& e){
            isRunning = false;
            break;
        }
        
    }
}
