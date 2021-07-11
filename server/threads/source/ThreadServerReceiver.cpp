#include "ThreadServerReceiver.h"

ThreadServerReceiver::ThreadServerReceiver(Socket &skt, NonBlockingQueue<std::unique_ptr<ClientEvent>> &queue):
 skt(skt), queue(queue), isRunning(false){}

void ThreadServerReceiver::run(){
    isRunning = true;
    CommunicationProtocol protocol(skt);
    while(isRunning){
        try{
            char buffer;

        } catch (const std::exception& e){
            isRunning = false;
            break;
        }
        
    }

}