#include "ThreadClient.h"
#include <unistd.h>

ThreadClient::ThreadClient(Socket &&peer, NonBlockingQueue<std::shared_ptr<Event>> &queueReceiver, 
		std::shared_ptr<BlockingQueue<std::string>> &queueSender, int id) : 
		peer(std::move(peer)), isRunning(false), clientEvents(queueReceiver), queueSender(queueSender),
		id(id) { }

ThreadClient::ThreadClient(ThreadClient &&other) : 
	peer(std::move(other.peer)), isRunning(other.isRunning),clientEvents(other.clientEvents),
	queueSender(other.queueSender), id(other.id) { }

ThreadClient::~ThreadClient() { }

void ThreadClient::run() {
	isRunning = true;
	ThreadServerReceiver receiver(peer, clientEvents);
	//ThreadServerSender sender(peer, queueSender, id);
	receiver.spawn();
	//sender.spawn();
	receiver.join();
	//sender.join();
	isRunning = false;
}

void ThreadClient::stop() { }

bool ThreadClient::isDead() const {
	return !isRunning;
}