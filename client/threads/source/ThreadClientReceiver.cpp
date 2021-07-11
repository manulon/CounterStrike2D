#include "ThreadClientReceiver.h"

ThreadClientReceiver::ThreadClientReceiver
(Socket &skt, NonBlockingQueue<std::shared_ptr<Event>> &queue):
skt(skt), queue(queue), isRunning(false){}

void ThreadClientReceiver::run(){
    isRunning = true;
    CommunicationProtocol protocol(skt);
    while(isRunning){
        try{
            int arg(0);
            int id(protocol.receive_size());
            char buffer(0);
            protocol.receive_message(1, &buffer);
            if (buffer == SHOOT){
                arg = protocol.receive_size();
            }
            std::shared_ptr<Event> event(new Event(id,buffer,arg));
            queue.push(std::move(event));
        } catch (const std::exception& e){
            isRunning = false;
            break;
        }
        
    }
}