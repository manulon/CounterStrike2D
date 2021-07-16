#include "Server.h"
#include "GamesMonitor.h"
#include "PlaintextMessage.h"
#include <chrono>
#include <iostream>
#include <thread>

void Server::run(const char* host, const char* service) {
    std::map<short, std::shared_ptr<BlockingQueue<ServerMessage*>>> senderQueues;
    Game game(MaxPlayers::FOUR, clientEvents, senderQueues);
    ThreadAcceptor acceptor(host, service, clientEvents, senderQueues);
    acceptor.spawn();
    game.joinPlayer(0);
    //game.joinPlayer(1);
    game.start();

    /*while (game.isReadyToStart()) {
        Event event = clientsEvents.pop();
        event.handleEvent(game);
    }*/


    std::string input("");
    while (input != "q"){
        std::cin >> input;
    }
    acceptor.stop();
    acceptor.join();
}