#ifndef _GAME_
#define _GAME_
#include "Thread.h"
#include <map>
#include <mutex>
#include <string>
#include "BlockingQueue.h"
#include "NonBlockingQueue.h"
#include "Event.h"
#include "ServerMessage.h"
#include <condition_variable>


class Game : public Thread {
	private:
		std::mutex mutex;
        std::condition_variable cv;
        std::map<short,BlockingQueue<ServerMessage>*> clientsQueues;
        NonBlockingQueue<std::shared_ptr<Event>> *clientEvents;
        // int numPlayers;
        // World world
		Game(const Game &other) = delete;
		Game(Game &&other) = delete;
		Game& operator=(const Game &other) = delete;
		Game& operator=(Game &&other);
        bool isReadyToStart();

	public:
		/*
		 * @brief Constructor.
		 */
		Game();
        virtual void run() override;
        //void addPlayer 
		/*
		 * @brief Destructor.
		 */
		~Game();

        NonBlockingQueue<std::shared_ptr<Event>>* addPlayer(BlockingQueue<ServerMessage>* bq);
        void createGame();
};

#endif 