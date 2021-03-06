// #include "Clients.h"
// #include "ThreadClient.h"
// #include <list>
// #include "NonBlockingQueue.h"
// #include "Event.h"
// #include <utility>

// // Clients::Clients( NonBlockingQueue<std::shared_ptr<ServerEvent>> &queue) : queue(queue) { }
// Clients::Clients(GamesMonitor &games) : games(games) { }

// // Clients::Clients(Clients &&other) : clients(std::move(other.clients)), queue(other.queue) { }
// Clients::Clients(Clients &&other) :  games(other.games), clients(std::move(other.clients)) { }

// Clients::~Clients() { }

// Clients& Clients::operator=(Clients &&other) {
// 	if (this == &other) return *this;
// 	clients = std::move(other.clients);
// 	return *this;
// }

// void Clients::add(Socket &&peer, int id) {
// 	// std::unique_ptr<BlockingQueue<std::string>> newQueue(new BlockingQueue<std::string>());
// 	// senderQueues[id] = std::move(newQueue);
// 	// std::unique_ptr<ThreadClient> client(new ThreadClient(std::move(peer),queue,senderQueues[id], id));
// 	std::unique_ptr<ThreadClient> client(new ThreadClient(std::move(peer),games));
// 	client->spawn();
// 	clients.push_back(std::move(client));
// }

// void Clients::cleanDeadClients() {
// 	std::list<std::unique_ptr<ThreadClient>>::iterator it = clients.begin();
// 	while(it != clients.end()) {
// 		if ((*it)->isDead()) {
// 			(*it)->join();			
// 			it = clients.erase(it);
// 		} else {
// 			++it;
// 		}
// 	}
// }

// void Clients::stopClients(){
// 	//for (ThreadClient &client : clients) {
// 	//	client->stop();
// 	//	client->join();
// 	//}
// 	std::list<std::unique_ptr<ThreadClient>>::iterator it = clients.begin();
// 	while(it != clients.end()) {
// 		(*it)->stop();
// 		(*it)->join();
// 	}
// }
