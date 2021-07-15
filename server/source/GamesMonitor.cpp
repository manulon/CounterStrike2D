#include "GamesMonitor.h"

#include <string>
#include <map>
#include <utility>

GamesMonitor::GamesMonitor() { }

GamesMonitor::~GamesMonitor() { }

/*NonBlockingQueue<std::shared_ptr<ServerEvent>>* GamesMonitor::joinOrCreate
					(const std::string &key, BlockingQueue<ServerMessage> *bq) {
	// std::lock_guard<std::mutex> lock(mutex);
	std::map<std::string, std::unique_ptr<Game>>::iterator it = games.find(key);
	if (it == games.end()) {
        std::unique_ptr<Game> game(new Game());
		games[key] = std::move(game);
		std::map<std::string, std::unique_ptr<Game>>::iterator it = games.find(key);
		it->second->createGame();
	}
	return it->second->addPlayer(bq);
}*/



