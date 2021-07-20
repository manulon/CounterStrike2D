#include "Server.h"
#include "GamesMonitor.h"
#include "PlaintextMessage.h"
#include <chrono>
#include <iostream>
#include <thread>

void Server::run(const char* host, const char* service) {
    std::map<short, std::shared_ptr<BlockingQueue<std::shared_ptr<ServerMessage>>>> senderQueues;
    Game game(MaxPlayers::FOUR, clientEvents, senderQueues);

    ThreadAcceptor acceptor(host, service, clientEvents, senderQueues);
    acceptor.spawn();

    game.spawn();

    std::string input("");
    while (input != "q" && input != "w"){
        std::cin >> input;
    }
    if (input == "w"){
        game.stop();  
    } 
    acceptor.stop();
    acceptor.join();
    game.join();
}