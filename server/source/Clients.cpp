#include "Clients.h"
#include "ThreadClient.h"
#include <list>
#include <utility>

Clients::Clients() { }

Clients::Clients(Clients &&other) : clients(std::move(other.clients)) { }

Clients::~Clients() { }

Clients& Clients::operator=(Clients &&other) {
	if (this == &other) return *this;
	clients = std::move(other.clients);
	return *this;
}

void Clients::add(Socket &&peer) {
	std::unique_ptr<ThreadClient> client(new ThreadClient(std::move(peer)));//, &nonBlockingQueue;
	client->run();
	clients.push_back(std::move(client));
}

void Clients::cleanDeadClients() {
	std::list<ThreadClient>::iterator it = clients.begin();
	while(it != clients.end()) {
		if ((*it)->isDead()) {
			(*it)->join();			
			it = clients.erase(it);
		} else {
			++it;
		}
	}
}

void Clients::stopClients() const {
	for (ThreadClient &client : clients) {
		client->stop();
		client->join();
	}
}
