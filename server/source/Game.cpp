#include "Game.h"

Game::Game() : clientEvents(new NonBlockingQueue<std::shared_ptr<Event>>()){}

Game::~Game(){}

void Game::run(){
    //cada 5 segundos pushear a los clientes

}

NonBlockingQueue<std::shared_ptr<Event>>* Game::addPlayer(BlockingQueue<ServerMessage>* bq){
    //se agrega al world
    //short id = world.addNewPlayer();
    // numPlayers++;
    std::cout<<"HAY "<<1<<" players\n";
    short id = 0;
    clientsQueues[id] = bq;
    cv.notify_all();
    return clientEvents;
}

void Game::createGame(){
    std::unique_lock<std::mutex> lock(mutex);
    std::cout<<"SE ESTA CREANDO LA PRIMERA\n";
    // while (!isReadyToStart()) 
    cv.wait(lock);
}

bool Game::isReadyToStart(){
    return (2 < 1);
}
