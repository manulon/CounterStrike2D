#include "ThreadAcceptor.h"


#include <iostream>
#include <utility>
#define SERVER_FLAGS AI_PASSIVE

ThreadAcceptor::ThreadAcceptor(const char *service, NonBlockingQueue<std::unique_ptr<Event>> &queue) 
	: ThreadAcceptor("localhost", service, queue) { }

ThreadAcceptor::ThreadAcceptor(const char *host, 
				   			   const char *service,
							   NonBlockingQueue<std::unique_ptr<Event>> &queue) 
	: acceptor(AI_PASSIVE), isRunning(true), queue(queue) { 
	acceptor.bindAndListen(host, service);
}

ThreadAcceptor::ThreadAcceptor(ThreadAcceptor &&other) : 
	acceptor(std::move(other.acceptor)), 
	isRunning(other.isRunning), queue(other.queue) { }

ThreadAcceptor::~ThreadAcceptor() { }

ThreadAcceptor& ThreadAcceptor::operator=(ThreadAcceptor &&other) {
	if (this == &other) return *this;
	acceptor = std::move(other.acceptor);
	isRunning = other.isRunning;
	return *this;
}

void ThreadAcceptor::run() {
	Clients clients(queue);
	int newId = 0;
	while (isRunning) {
		try { 
			Socket peer = acceptor.accept();
			clients.add(std::move(peer),newId);
			clients.cleanDeadClients();
			newId++;
		} catch(const std::exception &exception) {
			break;
		}
	}
	clients.stopClients();
}

void ThreadAcceptor::stop() {
	isRunning = false;
	acceptor.close();
}