#ifndef _GAME_
#define _GAME_

#include "Player.h"
#include "World.h"
#include "BlockingQueue.h"
#include "NonBlockingQueue.h"
#include "ServerMessage.h"
#include <map>
#include <mutex>
#include "PhysicalMapFactory.h"

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
        std::map<short,std::shared_ptr<BlockingQueue<std::shared_ptr<ServerMessage>>>> &senderQueues;

        std::map<short, std::shared_ptr<Player>> counterTerrorist;
        std::map<short, std::shared_ptr<Player>> terrorist;
        std::map<short, std::shared_ptr<Player>> allPlayers;
		std::vector<std::pair<float, float>> terroristsPositions;
		std::vector<std::pair<float, float>> counterTerroristsPositions;

		PhysicalMapFactory physicalMap;
		bool gameStarted;
        
		Game(const Game &other) = delete;
		Game(Game &&other) = delete;
		Game& operator=(const Game &other) = delete;
		Game& operator=(Game &&other) = delete;
		void sendInfoToClients();
		void sendLifeInfo();
		void sendPositions();
		void sendBullets();
		void sendWeapons();
		void notifyRestOfPlayers(short id);
		void joinOtherPlayers(short newPlayerId);
		void createTerrorist(short playerID, int position);
		void createCounterTerrorist(short playerID, int position);
		void cleanDeadPlayers();
		void cleanDeadTerrorists();
		void cleandDeadCounterTerrorists();
		void cleanAllPlayers();
		
	public:
		Game(MaxPlayers maxPlayers, 
			 NonBlockingQueue<std::shared_ptr<ServerEvent>> &queue,
			 std::map<short,std::shared_ptr<BlockingQueue<std::shared_ptr<ServerMessage>>>> &senderQueues);
		~Game();
		void joinPlayer(short playerID);
		bool isReadyToStart();
		bool isGameOver();
		void start();
		void shoot(short id, char angle);
		void playerMovement(short id, char opcode);

		void addTerroristPosition(float x, float y);
		void addCounterTerroristPosition(float x, float y);
		void removePlayer(short id);
};

#endif 