#include "Client.h"
#include "EventHandler.h"
#include "Window.h"
void Client::run(const char * host, const char *service){
    Socket skt;
    
    skt.connect(host,service);
     Window window("Counter Strike 2D", 800, 600, 
                  SDL_WINDOW_RESIZABLE, 
                  SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    ThreadClientReceiver receiver(skt, nonBlockingQueue);
    ThreadClientSender sender(skt, blockingQueue, 1);

    receiver.spawn();
    sender.spawn();

    EventHandler eh(skt,blockingQueue);
    std::shared_ptr<std::string> message;
    bool gameStarted = false;
    std::string command; 
    std::cout<<"----------------------------------------------------------------\n";
    std::cout<<"Ingrsar 'unirse' para unirse a la partida\n";
    while(!gameStarted){
        std::cin >> command;
        if (command == "unirse"){
            std::shared_ptr<ClientMessage> msg (new LoginMessage(JOIN,"-"));
            blockingQueue.push(msg);
            break;
        } 
        // do{
        //     message = nonBlockingQueue.pop();
        //     if (message != nullptr){
        //         std::cout<<*message<<std::endl;
        //     }
        // } while( message != nullptr);
    }

    bool isRunning(true);

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
