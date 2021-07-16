#include "Game.h"
#include "ProtocolConstants.h"
#include "ServerEvent.h"
#include "SWeapon.h"
#include "Ak47.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "LifeMessage.h"
#include "PlayerInfoMessage.h"

Game::Game(MaxPlayers maxPlayers, 
           NonBlockingQueue<std::shared_ptr<ServerEvent>> &queue,
           std::map<short,std::shared_ptr<BlockingQueue<ServerMessage*>>> &senderQueues) :
    world { },
    maxPlayers {maxPlayers},
    playersInGame {0},
    queue {queue},
    senderQueues {senderQueues} { }

Game::~Game() { }

void Game::start() {
    while (true) {
        std::shared_ptr<ServerEvent> event = queue.pop();
        while (event.get() != nullptr) {
            std::cout << "No paso\n";
            event->handle(*this);
            event = queue.pop();
            std::cout << "Paso\n";
        }
        world.step();
        sendInfoToClients();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        //iterar sobre todos los elementos de la cola
        //senderQueues.push(map);
    }
}

void Game::sendInfoToClients(){
    sendLifeInfo();
    sendPositions();
    // sendBullets();
    // sendWeapons();
}

void Game::sendLifeInfo(){
    for (auto& pair : terrorist){
        LifeMessage * msg = new LifeMessage(pair.second.getLife());
        senderQueues[pair.first]->push(msg);
    }
    for (auto& pair : counterTerrorist){
        LifeMessage * msg = new LifeMessage(pair.second.getLife());
        senderQueues[pair.first]->push(msg);
    }
}
void Game::sendPositions(){
    for (auto& pairPlayer : terrorist){
        for (auto& pair :senderQueues){
            PlayerInfoMessage *msg = new PlayerInfoMessage
                            (pairPlayer.first,pairPlayer.second.getPositionX(),pairPlayer.second.getPositionY(),11);
            pair.second->push(msg);
        }
    }
    for (auto& pairPlayer : counterTerrorist){
        for (auto& pair :senderQueues){
            PlayerInfoMessage *msg = new PlayerInfoMessage
                            (pairPlayer.first,pairPlayer.second.getPositionX(),pairPlayer.second.getPositionY(),11);
            pair.second->push(msg);
        }
    }
}


void Game::shoot(short id, char angle) {
    std::map<short, Player>::iterator it = terrorist.find(id);
    if (it == terrorist.end()) {
        it = counterTerrorist.find(id);
    }
    it->second.attack(angle);
}

void Game::playerMovement(short id, char opcode) {
    std::map<short, Player>::iterator it = terrorist.find(id);
    if (it == terrorist.end()) {
        it = counterTerrorist.find(id);
    }
    if (opcode == MOVE_LEFT) {
        it->second.moveLeft();
    } else if (opcode == MOVE_RIGHT) {
        it->second.moveRight();
    } else if (opcode == MOVE_DOWN) {
        it->second.moveDown();
    } else if (opcode == MOVE_UP) {
        it->second.moveUp();
    } else if (opcode == STOP_LEFT) {
        it->second.stopMoveLeft();
    } else if (opcode == STOP_RIGHT) {
        it->second.stopMoveRight();
    } else if (opcode == STOP_UP) {
        it->second.stopMoveUp();
    } else if (opcode == STOP_DOWN) {
        it->second.stopMoveDown();
    }
}

void Game::joinPlayer(short playerID) {
    if (isReadyToStart()) throw ("Maximo numero de jugadores alcanzados, intente en otra partida");
    
    std::lock_guard<std::mutex> lock(mutex);
    Player player(world, 2.1f, 8.2f, 2.0f, 2.0f, 1);
    std::unique_ptr<Ak47> ak47(new Ak47(world, 0.2f, 0.2f));
    player.setPrimaryWeapon(std::move(ak47));

    std::pair<std::map<short, Player>::iterator, bool> insertRet;
    if (playersInGame % 2 == 0) {
        std::cout<<"agregadi a counter terrorist\n";
        insertRet = counterTerrorist.insert(std::pair<short, Player>(playerID, std::move(player)));
    } else {
        std::cout<<"agregado a terroist\n";
        insertRet = terrorist.insert(std::pair<short, Player>(playerID, std::move(player)));
    }
    if (insertRet.second == false) throw ("Ya existe un jugador con ese ID");
    ++playersInGame;
}

bool Game::isReadyToStart() {
    return playersInGame == maxPlayers ? true : false; 
}

bool Game::isGameOver() {
    bool gameOver = false;
    if (terrorist.size() == 10) {
        // para cada elemento de la cola enviadora
        // con clave impar
        // senderQueue.push("Derrota")

        // para cada elemento de la cola enviadora
        // con clave par
        // senderQueue.push("Victoria")

        gameOver = true;
    }
    if (counterTerrorist.size() == 10) {
        // para cada elemento de la cola enviadora
        // con clave impar
        // senderQueue.push("Victoria")

        // para cada elemento de la cola enviadora
        // con clave par
        // senderQueue.push("Derrota")

        gameOver = true;
    }
    return gameOver;
}
