#include "Server.h"
#include "GamesMonitor.h"
#include "PlaintextMessage.h"
#include <chrono>
#include <iostream>
#include <thread>

void Server::run(const char* host, const char* service){
    GamesMonitor games;
    // Clients clients(games);
    std::map<short,BlockingQueue<ServerMessage*>*>  senderQueues;
    ThreadAcceptor acceptor(host, service,clientEvents,senderQueues);
    std::cout<<"Spawnee el aceptor "<< std::endl;
    acceptor.spawn();
    std::cout<<"ESPERANDO PARA PUSHEAR MENSAJES "<< std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(20000));
    std::cout<<"MENSAJES PUSHEADOS"<< std::endl;
    std::cout<<"la lista tiene tamano "<<senderQueues.size()<<std::endl;
    for (auto& it : senderQueues){
        it.second->push(new PlaintextMessage("mensaje pa todos los clientes"));
    }
    std::string input("");
    while (input != "q"){
        std::cin >> input;
    }
    acceptor.stop();
    acceptor.join();
}