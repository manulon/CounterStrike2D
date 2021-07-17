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
#include "BulletMessage.h"
#include "WeaponMessage.h"
#include "OtherPlayerJoinedMessage.h"
#include "JoinMessage.h"

Game::Game(MaxPlayers maxPlayers, 
           NonBlockingQueue<std::shared_ptr<ServerEvent>> &queue,
           std::map<short,std::shared_ptr<BlockingQueue<ServerMessage*>>> &senderQueues) :
    world { },
    maxPlayers {maxPlayers},
    playersInGame {0},
    queue {queue},
    senderQueues {senderQueues},
    physicalMap{world,"../mapaGiganteDust.yaml"},
    gameStarted{false} { }

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
        for (auto& pair : allPlayers){
            pair.second->update();
        }
        if (allPlayers.size() == 0 && gameStarted == true){
            break;
        }
        world.step();
        // cleanDeadPlayers();
        sendInfoToClients();
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        //iterar sobre todos los elementos de la cola
        //senderQueues.push(map);
    }
}

void Game::sendInfoToClients(){
    sendLifeInfo();
    sendPositions();
    sendBullets();
    sendWeapons();
}

void Game::sendLifeInfo(){
    for (auto& pair : terrorist){
        LifeMessage * msg = new LifeMessage(pair.second->getLife());
        senderQueues[pair.first]->push(msg);
    }
    for (auto& pair : counterTerrorist){
        LifeMessage * msg = new LifeMessage(pair.second->getLife());
        senderQueues[pair.first]->push(msg);
    }
}
void Game::sendPositions(){
    for (auto& pairPlayer : terrorist){
        for (auto& pair : allPlayers){
            PlayerInfoMessage *msg = new PlayerInfoMessage
                            (pairPlayer.first,pairPlayer.second->getPositionX(),pairPlayer.second->getPositionY(),11);
            senderQueues[pair.first]->push(msg);
        }
    }
    for (auto& pairPlayer : counterTerrorist){
        for (auto& pair : allPlayers){
            PlayerInfoMessage *msg = new PlayerInfoMessage
                            (pairPlayer.first,pairPlayer.second->getPositionX(),pairPlayer.second->getPositionY(),11);
            senderQueues[pair.first]->push(msg);
        }
    }
}

void Game::sendBullets(){
    std::list<std::shared_ptr<Bullet>> actualBullets;
    world.getBulletsList(actualBullets);

    for (auto& pairPlayer : terrorist){
        for (auto& bullet: actualBullets){
            BulletMessage *msg = new BulletMessage(bullet->getPositionX(),bullet->getPositionY());
            senderQueues[pairPlayer.first]->push(msg);
        }   
    }
    for (auto& pairPlayer : counterTerrorist){
        for (auto& bullet: actualBullets){
            BulletMessage *msg = new BulletMessage(bullet->getPositionX(),bullet->getPositionY());
            senderQueues[pairPlayer.first]->push(msg);
        }
    }
}

void Game::sendWeapons(){
    std::list<std::shared_ptr<SWeapon>> actualWeapons;
    world.getWeaponList(actualWeapons);

    for (auto& pairPlayer : terrorist){
        for (auto& weapon: actualWeapons){
            WeaponMessage *msg = new WeaponMessage
                                    (weapon->getId(),weapon->getPositionX(),weapon->getPositionY());
            senderQueues[pairPlayer.first]->push(msg);
        }   
    }
    for (auto& pairPlayer : counterTerrorist){
        for (auto& weapon: actualWeapons){
            WeaponMessage *msg = new WeaponMessage
                                    (weapon->getId(),weapon->getPositionX(),weapon->getPositionY());
            senderQueues[pairPlayer.first]->push(msg);
        }
    }
}

void Game::shoot(short id, char angle) {
    std::map<short, std::shared_ptr<Player>>::iterator it = terrorist.find(id);
    if (it == terrorist.end()) {
        it = counterTerrorist.find(id);
    }
    it->second->attack(angle);
}

void Game::playerMovement(short id, char opcode) {
    std::map<short, std::shared_ptr<Player>>::iterator it = terrorist.find(id);
    if (it == terrorist.end()) {
        it = counterTerrorist.find(id);
    }
    if (opcode == MOVE_LEFT) {
        it->second->moveLeft();
    } else if (opcode == MOVE_RIGHT) {
        it->second->moveRight();
    } else if (opcode == MOVE_DOWN) {
        it->second->moveDown();
    } else if (opcode == MOVE_UP) {
        it->second->moveUp();
    } else if (opcode == STOP_LEFT) {
        it->second->stopMoveLeft();
    } else if (opcode == STOP_RIGHT) {
        it->second->stopMoveRight();
    } else if (opcode == STOP_UP) {
        it->second->stopMoveUp();
    } else if (opcode == STOP_DOWN) {
        it->second->stopMoveDown();
    }
}

void Game::joinPlayer(short playerID) {
    if (isReadyToStart()) throw ("Maximo numero de jugadores alcanzados, intente en otra partida");
    gameStarted = true;
    std::lock_guard<std::mutex> lock(mutex);
    std::shared_ptr<Player> player(new Player(world, 1.0f, 0.0f, 0.45f, 0.45f, 1));
    std::unique_ptr<Ak47> ak47(new Ak47(world, 0.2f, 0.2f));
    player->setPrimaryWeapon(std::move(ak47));

    std::pair<std::map<short, std::shared_ptr<Player>>::iterator, bool> insertRet;
    if (playersInGame % 2 == 0) {
        insertRet = counterTerrorist.insert(std::pair<short, std::shared_ptr<Player>>(playerID, player));
    } else {
        insertRet = terrorist.insert(std::pair<short, std::shared_ptr<Player>>(playerID, player));
    }
    allPlayers.insert(std::pair<short, std::shared_ptr<Player>>(playerID,player));
    ServerMessage * idMessage = new JoinMessage(playerID);
    senderQueues[playerID]->push(idMessage);
    joinOtherPlayers(playerID);
    notifyRestOfPlayers(playerID);
    if (insertRet.second == false) throw ("Ya existe un jugador con ese ID");
    ++playersInGame;
}

void Game::removePlayer(short id){
    allPlayers.erase(id);
    if (id % 2 == 0) {
        counterTerrorist.erase(id);
    } else {
        terrorist.erase(id);
    }
    std::cout<<"--------------------------------\n";
    std::cout<<"--------------------------------\n";
    std::cout<<"JUGADOR ELIMINADO EL MAPA TIENE TAMANIO "<<allPlayers.size()<<std::endl;
    std::cout<<"--------------------------------\n";
    std::cout<<"--------------------------------\n";
}

//Cuando un jugador se une se le comunica el resto de los jugadores que estan en la partida
void Game::joinOtherPlayers(short newPlayerId){
    for (auto& pair : allPlayers){
        if (pair.first != newPlayerId){
            senderQueues[newPlayerId]->push(new OtherPlayerJoinedMessage(pair.first));
        }
    }
}

void Game::notifyRestOfPlayers(short playerID){
    for (auto & pair : allPlayers){
        if (pair.first != playerID)
            senderQueues[pair.first]->push(new OtherPlayerJoinedMessage(playerID));
    }
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
