#ifndef _GAMES_MONITOR_H_
#define _GAMES_MONITOR_H_

#include <map>
#include <mutex>
#include <string>
#include "Game.h"
#include <memory>

class GamesMonitor {
	private:
		std::map<std::string, std::unique_ptr<Game>> games;
		std::mutex mutex;
		GamesMonitor(const GamesMonitor &other) = delete;
		GamesMonitor(GamesMonitor &&other) = delete;
		GamesMonitor& operator=(const GamesMonitor &other) = delete;
		GamesMonitor& operator=(GamesMonitor &&other) = delete;

	public:
		/*
		 * @brief Constructor.
		 */
		GamesMonitor();

		/*
		 * @brief Destructor.
		 */
		~GamesMonitor();

		NonBlockingQueue<std::shared_ptr<Event>>* joinOrCreate
			(const std::string &key, BlockingQueue<ServerMessage> *bq);
};

#endif // _GAMES_MONITOR_H_