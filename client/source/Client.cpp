#include "Client.h"
#include "EventHandler.h"

void Client::run(const char * host, const char *service){
    Socket skt;
    
    skt.connect(host,service);

    //ThreadClientReceiver receiver(skt, nonBlockingQueue);
    ThreadClientSender sender(skt, blockingQueue, 1);

    //receiver.spawn();
    sender.spawn();

    EventHandler eh(skt, blockingQueue);
    bool isRunning(true);
    while (isRunning){
        isRunning = eh.handleEvents();
    }
    //receiver.join();
    sender.join();
}
