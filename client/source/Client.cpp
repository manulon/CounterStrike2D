#include "Client.h"
#include "EventHandler.h"

void Client::run(const char * host, const char *service){
    Socket skt;
    
    skt.connect(host,service);

    ThreadClientReceiver receiver(skt, nonBlockingQueue);
    ThreadClientSender sender(skt, blockingQueue, 1);

    receiver.spawn();
    sender.spawn();

    EventHandler eh(skt,blockingQueue);
    bool isRunning(true);
    std::shared_ptr<std::string> message;



    while (isRunning){
        do{
            message = nonBlockingQueue.pop();
            if (message != nullptr) {
                // std::string pepe(message);
                std::cout <<"MENSAJE RECIBIDO:"<<*message <<"y"<< std::endl;
            }
        } while (message != NULL);
        isRunning = eh.handleEvents();
    }
    std::cout<<"SALE DEL LOOP\n";
    receiver.join();
    std::cout<<"SE JOINEA EL RECIBIDOR\n";
    sender.join();
    std::cout<<"SE JOINEA EL ENVIADOR\n";
}
