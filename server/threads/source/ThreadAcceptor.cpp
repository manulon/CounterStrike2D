#include "ThreadAcceptor.h"
#include <iostream>
#include <utility>
#define SERVER_FLAGS AI_PASSIVE

ThreadAcceptor::ThreadAcceptor(const char *host, 
				   			   const char *service,
							    NonBlockingQueue<std::shared_ptr<ServerEvent>> &queue,
								std::map<short,std::shared_ptr<BlockingQueue<ServerMessage*>>> & senderQueues) 
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
		std::get<2>(client.second)->stop();
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

	short clientID = 0;
	while (isRunning) {
		try { 
			Socket peer = acceptor.accept();
			clients.insert(std::make_pair(clientID, std::make_tuple(std::move(peer),nullptr,nullptr)));
			std::map<short,std::tuple<Socket,ThreadServerReceiver*,ThreadServerSender*>>::iterator it = clients.find(clientID);

			std::shared_ptr<BlockingQueue<ServerMessage*>> senderQueue(new BlockingQueue<ServerMessage*>);
			std::get<2>(it->second) = new ThreadServerSender(std::get<0>(it->second), senderQueue);
			std::get<2>(it->second)->spawn();
			
			senderQueues.insert(std::make_pair(clientID, senderQueue));
			std::get<1>(it->second) = new ThreadServerReceiver(std::get<0>(it->second), queue, clientID);
			std::get<1>(it->second)->spawn();

			std::cout<<std::endl<<"Conexion establecida..."<<std::endl;
			cleanDeadClients();
			++clientID;
		} catch (const std::exception &exception) { 
			std::cout<<"se cierra el aceptador\n";
		}
	}
}

void ThreadAcceptor::stop() {
	isRunning = false;
	acceptor.close();
}

void ThreadAcceptor::cleanDeadClients() {
	std::map<short, 
			 std::tuple<Socket, 
					    ThreadServerReceiver*, 
					    ThreadServerSender*>>::iterator it = clients.begin();
	while (it != clients.end()){
		if (std::get<1>(it->second)->isDead()
		   || std::get<2>(it->second)->isDead()){
			std::get<1>(it->second)->join();
			std::get<2>(it->second)->join();
			delete std::get<1>(it->second);
			delete std::get<2>(it->second);
			it = clients.erase(it);
		} else {
			it++;
		}
	}
}
