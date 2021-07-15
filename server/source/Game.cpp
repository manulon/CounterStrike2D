#include "Game.h"
#include "ProtocolConstants.h"
#include <iostream>

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
    while (!isGameOver()) {
        std::shared_ptr<ServerEvent> event = queue.pop();
        while (event.get() != nullptr) {
            event = queue.pop();
            event->handle(*this);
        }
        world.step();
        //iterar sobre todos los elementos de la cola
        //senderQueues.push(map);
    }
}

void Game::shoot(short id, char angle) {
    players[id].shoot(angle);
}

void Game::playerMovement(short id, char opcode) {
    if (opcode = MOVE_LEFT) {
        players[id].moveLeft();
    } else if (opcode = MOVE_RIGHT) {
        players[id].moveRight();
    } else if (opcode = MOVE_DOWN) {
        players[id].moveDown();
    } else if (opcode = MOVE_UP) {
        players[id].moveUp();
    } else if (opcode = STOP_LEFT) {
        players[id].stopMoveLeft();
    } else if (opcode = STOP_RIGHT) {
        players[id].stopMoveRight();
    } else if (opcode = STOP_UP) {
        players[id].stopMoveUp();
    } else (opcode = STOP_DOWN) {
        players[id].stopMoveDown();
    }
}

void Game::joinPlayer(short playerID) {
    if (isReadyToStart()) throw ("Maximo numero de jugadores alcanzados, intente en otra partida");
    
    std::lock_guard<std::mutex> lock(mutex);
    Player player(world, 2.0f, 8.0f, 2.0f, 2.0f, 1);  
    std::pair<std::map<uint8_t, Player>::iterator, bool> insertRet;
    if (playersInGame % 2 == 0) {
        insertRet = counterTerrorist.insert(std::pair<uint8_t, Player>(playerID, std::move(player)));
    } else {
        insertRet = terrorist.insert(std::pair<uint8_t, Player>(playerID, std::move(player)));
    }
    if (insertRet.second == false) throw ("Ya existe un jugador con ese ID");
    ++playersInGame;
}

bool Game::isReadyToStart() {
    return playersInGame == maxPlayers ? true : false; 
}

bool Game::isGameOver() {
    bool gameOver = false;
    if (terrorist.size() == 0) {
        // para cada elemento de la cola enviadora
        // con clave impar
        // senderQueue.push("Derrota")

        // para cada elemento de la cola enviadora
        // con clave par
        // senderQueue.push("Victoria")

        gameOver = true;
    }
    if (counterTerrorist.size() == 0) {
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
