#include "ThreadAcceptor.h"


#include <iostream>
#include <utility>
#define SERVER_FLAGS AI_PASSIVE

// ThreadAcceptor::ThreadAcceptor(const char *service, NonBlockingQueue<std::shared_ptr<Event>> &queue) 
// 	: ThreadAcceptor("localhost", service, queue) { }

ThreadAcceptor::ThreadAcceptor(const char *host, 
				   			   const char *service,
							    NonBlockingQueue<std::shared_ptr<Event>> &queue,
								std::map<short,BlockingQueue<ServerMessage*>*> & senderQueues) 
	: acceptor(AI_PASSIVE), isRunning(true), queue(queue) ,senderQueues(senderQueues){ 
	acceptor.bindAndListen(host, service);
}

// ThreadAcceptor::ThreadAcceptor(ThreadAcceptor &&other) : 
// 	acceptor(std::move(other.acceptor)), 
// 	isRunning(other.isRunning), clients(other.clients) { }

ThreadAcceptor::~ThreadAcceptor() { 
	for (auto& client : clients){
		std::get<1>(client.second)->join();
		delete std::get<1>(client.second);
		std::get<2>(client.second)->join();
		delete std::get<2>(client.second);
	}
}

ThreadAcceptor& ThreadAcceptor::operator=(ThreadAcceptor &&other) {
	if (this == &other) return *this;
	acceptor = std::move(other.acceptor);
	isRunning = other.isRunning;
	return *this;
}

void ThreadAcceptor::run() {
	// Clients clients(queue);
	short newId = 0;
	while (isRunning) {
		try { 
			Socket peer = acceptor.accept();
			BlockingQueue<ServerMessage*> *senderQueue = new BlockingQueue<ServerMessage*>;
			senderQueues.insert(std::make_pair(newId,senderQueue));

			clients.insert(std::make_pair(newId,std::make_tuple(std::move(peer),nullptr,nullptr)));
			std::map<short,std::tuple<Socket,ThreadServerReceiver*,ThreadServerSender*>>::iterator it = clients.find(newId);
			std::get<1>(it->second) = new ThreadServerReceiver(std::get<0>(it->second),queue);
			std::get<1>(it->second)->spawn();
			std::get<2>(it->second) = new ThreadServerSender(std::get<0>(it->second),senderQueue);
			std::get<2>(it->second)->spawn();


			std::cout<<std::endl<<"Conexion establecida..."<<std::endl;

			cleanDeadClients();
			newId++;
		} catch(const std::exception &exception) { }
	}
	// clients.stopClients();
}

void ThreadAcceptor::stop() {
	isRunning = false;
	acceptor.close();
}

void ThreadAcceptor::cleanDeadClients(){
	std::map<short,std::tuple<Socket,ThreadServerReceiver*,ThreadServerSender*>>::iterator it = clients.begin();
	while (it != clients.end()){
		if (std::get<1>(it->second)->isDead()
		   || std::get<2>(it->second)->isDead()){
			std::get<1>(it->second)->join();
			std::get<2>(it->second)->join();
			delete std::get<1>(it->second);
			delete std::get<2>(it->second);
			it = clients.erase(it);
		}else {
			it++;
		}
	}
}



