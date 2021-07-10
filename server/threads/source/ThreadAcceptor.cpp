#include "ThreadAcceptor.h"
#include "Clients.h"

#include <iostream>
#include <utility>
#define SERVER_FLAGS AI_PASSIVE

ThreadAcceptor::ThreadAcceptor(const char *service) 
	: ThreadAcceptor("localhost", service) { }

ThreadAcceptor::ThreadAcceptor(const char *host, 
				   			   const char *service) 
	: acceptor(AI_PASSIVE), isRunning(true) { 
	acceptor.bindAndListen(host, service);
}

ThreadAcceptor::ThreadAcceptor(ThreadAcceptor &&other) : 
	acceptor(std::move(other.acceptor)), 
	isRunning(other.isRunning) { }

ThreadAcceptor::~ThreadAcceptor() { }

ThreadAcceptor& ThreadAcceptor::operator=(ThreadAcceptor &&other) {
	if (this == &other) return *this;
	acceptor = std::move(other.acceptor);
	isRunning = other.isRunning;
	return *this;
}

void ThreadAcceptor::run() {
	Clients clients;

	while (isRunning) {
		try { 
			Socket peer = acceptor.accept();
			clients.add(std::move(peer));
			clients.cleanDeadClients();
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