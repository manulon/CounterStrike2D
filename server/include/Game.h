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
#include "Thread.h"
#include <atomic>
class ServerEvent;
enum MaxPlayers {
	TWO = 2,
	FOUR = 4,
	SIX = 6,
	EIGHT = 8,
	TEN = 10
};

class Game : public Thread {
	private:
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
		std::vector<std::tuple<float, float, int>> weaponsPositions;

		std::unique_ptr<PhysicalMapFactory> physicalMap;
		bool gameStarted;
        std::atomic<bool> isRunning;
		bool counterTerroristsWin;
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
		void executeFrame();
		void createWeapons();
		void createWeapon(int position);
		
	public:
		Game(MaxPlayers maxPlayers, 
			 NonBlockingQueue<std::shared_ptr<ServerEvent>> &queue,
			 std::map<short,std::shared_ptr<BlockingQueue<std::shared_ptr<ServerMessage>>>> &senderQueues);
		~Game();
		void joinPlayer(short playerID);
		bool isReadyToStart();
		bool isGameOver();
		virtual void run () override;
		void shoot(short id, short angle);
		void playerMovement(short id, char opcode);

		void addTerroristPosition(float x, float y);
		void addCounterTerroristPosition(float x, float y);
		void addWeaponPosition(float x, float y, int id);
		void removePlayer(short id);
		void pickUpWeapon(short id);
		void stopPickingUpWeapon(short id);
		void setPlayerAngle(short id, short angle);
		bool hasStarted();
		void setMap(std::string name);
		void switchWeapon(short id, char weapon);
		void stop();
		void notifyResults();
};

#endif 