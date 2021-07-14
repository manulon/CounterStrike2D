// #include "ThreadClient.h"
// #include <unistd.h>
// #include "ServerMessage.h"

// // ThreadClient::ThreadClient(Socket &&peer, NonBlockingQueue<std::shared_ptr<Event>> &queueReceiver, 
// // 		std::shared_ptr<BlockingQueue<std::string>> &queueSender, int id) : 
// // 		peer(std::move(peer)), isRunning(false), clientEvents(queueReceiver), queueSender(queueSender),
// // 		id(id) { }


// ThreadClient::ThreadClient(Socket &&peer, GamesMonitor &games) : 
// 		peer(std::move(peer)), isRunning(false), games(games) { }


// ThreadClient::ThreadClient(ThreadClient &&other) : 
// 	peer(std::move(other.peer)), isRunning(other.isRunning), games(other.games) { }

// ThreadClient::~ThreadClient() { }

// void ThreadClient::run() {
// 	isRunning = true;

// 	BlockingQueue<ServerMessage> bq;
// 	// Login login(games);
// 	// NonBlockingQueue<std::shared_ptr<Event>> * nbq = login.registerUser(peer, bq);
// 		NonBlockingQueue<std::shared_ptr<Event>> * nbq = nullptr;
// 	{
// 		nbq = games.joinOrCreate("partida1", &bq);
// 	}
// 	ThreadServerReceiver receiver(peer,nbq );
// 	ThreadServerSender sender(peer, &bq);
// 	receiver.spawn();
// 	sender.spawn();
// 	receiver.join();
// 	sender.join();
// 	isRunning = false;
// }

// void ThreadClient::stop() { }

// bool ThreadClient::isDead() const {
// 	return !isRunning;
// }