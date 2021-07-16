#ifndef _GAME_
#define _GAME_

#include "Player.h"
#include "World.h"
#include "BlockingQueue.h"
#include "NonBlockingQueue.h"
#include "ServerMessage.h"
// #include "ServerEvent.h"
#include <map>
#include <mutex>

class ServerEvent;
enum MaxPlayers {
	TWO = 2,
	FOUR = 4,
	SIX = 6,
	EIGHT = 8,
	TEN = 10
};

class Game {
	private:
        std::mutex mutex;
       	
       	World world;
        MaxPlayers maxPlayers;
        short playersInGame;

        NonBlockingQueue<std::shared_ptr<ServerEvent>> &queue;
        std::map<short,std::shared_ptr<BlockingQueue<ServerMessage*>>> &senderQueues;

        std::map<short, Player> counterTerrorist;
        std::map<short, Player> terrorist;
        
		Game(const Game &other) = delete;
		Game(Game &&other) = delete;
		Game& operator=(const Game &other) = delete;
		Game& operator=(Game &&other) = delete;
		void sendInfoToClients();
		void sendLifeInfo();
		void sendPositions();
		void sendBullets();
		void sendWeapons();

	public:
		Game(MaxPlayers maxPlayers, 
			 NonBlockingQueue<std::shared_ptr<ServerEvent>> &queue,
			 std::map<short,std::shared_ptr<BlockingQueue<ServerMessage*>>> &senderQueues);
		~Game();
		void joinPlayer(short playerID);
		bool isReadyToStart();
		bool isGameOver();
		void start();
		void shoot(short id, char angle);
		void playerMovement(short id, char opcode);
};

#endif 