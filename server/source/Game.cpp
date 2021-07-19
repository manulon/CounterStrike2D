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
           std::map<short,std::shared_ptr<BlockingQueue<std::shared_ptr<ServerMessage>>>> &senderQueues) :
    world { },
    maxPlayers {maxPlayers},
    playersInGame {0},
    queue {queue},
    senderQueues {senderQueues},
    physicalMap{world,"../assets/maps/mapaGiganteDust.yaml", *this},
    gameStarted{false} { } //OJO CON MOVER UN GAME, y el this

Game::~Game() { }

void Game::start() {
    while (true) {
        std::shared_ptr<ServerEvent> event = queue.pop();
        while (event.get() != nullptr) {
            event->handle(*this);
            event = queue.pop();
        }
        for (auto& pair : allPlayers){
            pair.second->update();
        }
        if (allPlayers.size() == 0 && gameStarted == true){
            break;
        }
        world.step();
        cleanDeadPlayers();
        sendInfoToClients();
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
    }
}

void Game::cleanDeadPlayers() {
    cleanDeadTerrorists();
    cleandDeadCounterTerrorists();
    cleanAllPlayers();
}

void Game::cleanDeadTerrorists() {
    std::map<short, std::shared_ptr<Player>>::iterator it = terrorist.begin();
    while(it != terrorist.end()) {
        if (it->second->isDead()) {
            it = terrorist.erase(it);
        } else {
            ++it;
        }
    }
}

void Game::cleandDeadCounterTerrorists() {
    std::map<short, std::shared_ptr<Player>>::iterator it = counterTerrorist.begin();
    while(it != counterTerrorist.end()) {
        if (it->second->isDead()) {
            it = counterTerrorist.erase(it);
        } else {
            ++it;
        }
    }    
}

void Game::cleanAllPlayers() {
    std::map<short, std::shared_ptr<Player>>::iterator it = allPlayers.begin();
    while(it != allPlayers.end()) {
        if (it->second->isDead()) {
            it = allPlayers.erase(it);
        } else {
            ++it;
        }
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
        std::shared_ptr<ServerMessage> msg(new LifeMessage(pair.second->getLife()));
        senderQueues[pair.first]->push(msg);
    }
    for (auto& pair : counterTerrorist){
        std::shared_ptr<ServerMessage> msg(new LifeMessage(pair.second->getLife()));
        senderQueues[pair.first]->push(msg);
    }
}

void Game::sendPositions(){
    for (auto& pairPlayer : terrorist){
        std::shared_ptr<ServerMessage> msg(new PlayerInfoMessage
                            (pairPlayer.first,pairPlayer.second->getPositionX(),pairPlayer.second->getPositionY(),11));
        for (auto& pair : allPlayers){
            senderQueues[pair.first]->push(msg);
        }
    }
    for (auto& pairPlayer : counterTerrorist){
        std::shared_ptr<ServerMessage> msg(new PlayerInfoMessage
                            (pairPlayer.first,pairPlayer.second->getPositionX(),pairPlayer.second->getPositionY(),11));
        for (auto& pair : allPlayers){
            senderQueues[pair.first]->push(msg);
        }
    }
}

void Game::sendBullets(){
    std::list<std::shared_ptr<Bullet>> actualBullets;
    world.getBulletsList(actualBullets);
    for (auto & bullet : actualBullets){
        std::shared_ptr<ServerMessage> msg(new BulletMessage(bullet->getPositionX(),bullet->getPositionY()));
        for (auto& pair : allPlayers){
            senderQueues[pair.first]->push(msg);
        }
    }

}
    // for (auto& pairPlayer : terrorist){
    //     for (auto& bullet: actualBullets){
    //         BulletMessage *msg = new BulletMessage(bullet->getPositionX(),bullet->getPositionY());
    //         senderQueues[pairPlayer.first]->push(msg);
    //     }   
    // }
    // for (auto& pairPlayer : counterTerrorist){
    //     for (auto& bullet: actualBullets){
    //         BulletMessage *msg = new BulletMessage(bullet->getPositionX(),bullet->getPositionY());
    //         senderQueues[pairPlayer.first]->push(msg);
    //     }
    // }

void Game::sendWeapons(){
    std::list<std::shared_ptr<SWeapon>> actualWeapons;
    world.getWeaponList(actualWeapons);
    for (auto & weapon : actualWeapons){
        std::shared_ptr<ServerMessage> msg
            (new WeaponMessage(weapon->getId(),weapon->getPositionX(),weapon->getPositionY()));
        for (auto& pair : allPlayers){
            senderQueues[pair.first]->push(msg);
        }
    }

}

void Game::shoot(short id, short angle) {
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
    { 
        std::lock_guard<std::mutex> lock(mutex);
        if (playersInGame % 2 == 0) {
            createCounterTerrorist(playerID, playersInGame/2);
        } else {
            createTerrorist(playerID, playersInGame/2);
        }
        ++playersInGame;
    }
    std::shared_ptr<ServerMessage> idMessage(new JoinMessage(playerID));
    senderQueues[playerID]->push(idMessage);
    joinOtherPlayers(playerID);
    notifyRestOfPlayers(playerID);
}

void Game::createTerrorist(short playerID, int position) {
    std::pair<std::map<short, std::shared_ptr<Player>>::iterator, bool> insertRet;
    float x = terroristsPositions[position].first;
    float y = terroristsPositions[position].second;

    std::shared_ptr<Player> player(new Player(world, x, y, 0.45f, 0.45f, 1));
    std::unique_ptr<Ak47> ak47(new Ak47(world, 0.2f, 0.2f));
    player->setPrimaryWeapon(std::move(ak47));
    insertRet = terrorist.insert(std::pair<short, std::shared_ptr<Player>>(playerID, player));

    if (insertRet.second == false) throw ("Ya existe un jugador con ese ID");
    allPlayers.insert(std::pair<short, std::shared_ptr<Player>>(playerID, player));
}

void Game::createCounterTerrorist(short playerID, int position) {
    std::pair<std::map<short, std::shared_ptr<Player>>::iterator, bool> insertRet;
    float x = counterTerroristsPositions[position].first;
    float y = counterTerroristsPositions[position].second;

    std::shared_ptr<Player> player(new Player(world, x, y, 0.45f, 0.45f, 1));
    std::unique_ptr<Ak47> ak47(new Ak47(world, 0.2f, 0.2f));
    player->setPrimaryWeapon(std::move(ak47));
    insertRet = counterTerrorist.insert(std::pair<short, std::shared_ptr<Player>>(playerID, player));

    if (insertRet.second == false) throw ("Ya existe un jugador con ese ID");
    allPlayers.insert(std::pair<short, std::shared_ptr<Player>>(playerID, player));
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
            std::shared_ptr<OtherPlayerJoinedMessage> msg(new OtherPlayerJoinedMessage(pair.first));
            senderQueues[newPlayerId]->push(msg);
        }
    }
}

void Game::notifyRestOfPlayers(short playerID){
    for (auto & pair : allPlayers){
        if (pair.first != playerID){
            std::shared_ptr<OtherPlayerJoinedMessage> msg(new OtherPlayerJoinedMessage(playerID));
            senderQueues[pair.first]->push(msg);
        }
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

void Game::addTerroristPosition(float x, float y) {
    std::vector<std::pair<float, float>>::iterator it = terroristsPositions.end();
    std::pair<float, float> position(x,y);
    terroristsPositions.insert(it, std::move(position));
}

void Game::addCounterTerroristPosition(float x, float y) {
    std::vector<std::pair<float, float>>::iterator it = counterTerroristsPositions.end();
    std::pair<float, float> position(x,y);
    counterTerroristsPositions.insert(it, std::move(position));
}

void Game::pickUpWeapon(short id){
    std::map<short, std::shared_ptr<Player>>::iterator it = terrorist.find(id);
    if (it == terrorist.end()) {
        it = counterTerrorist.find(id);
    }
    it->second->pickUpWeapon();
}

void Game::stopPickingUpWeapon(short id){
    std::map<short, std::shared_ptr<Player>>::iterator it = terrorist.find(id);
    if (it == terrorist.end()) {
        it = counterTerrorist.find(id);
    }
    it->second->stopPickingUpWeapon();
}