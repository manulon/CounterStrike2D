#include "ThreadClient.h"
#include "BlockingQueue.h"
#include "ThreadServerReceiver.h"
#include "ThreadServerSender.h"
#include <string>
#include <utility>

ThreadClient::ThreadClient(Socket &&peer) : 
	peer(std::move(peer)), isRunning(true) { }

ThreadClient::ThreadClient(ThreadClient &&other) : 
	peer(std::move(other.peer)), isRunning(other.isRunning) { }

ThreadClient::~ThreadClient() { }

void ThreadClient::run() {
	BlockingQueue messagesToClient;
	ThreadServerReceiver receiver;
	ThreadServerSender sender;

	//CommunicationProtocol communicationProtocol(peer);

	/*ssize_t receivedBytes = communicationProtocol.receiveCommand(buffer);
	while(receivedBytes != 0) {
		if (buffer.compare("0x6E") == 0) {
			communicationProtocol.receive(buffer);
			if (gameName.empty()) {
				tateti.setPlayerOne(player);
				gameName = buffer;
				gamesMonitor.putIfAbsent(std::move(buffer), tateti);
				buffer = gamesMonitor[gameName].toString(player);
			}

		} else if (buffer.compare("0x6C") == 0) {
			buffer = gamesMonitor.toString();

		} else if (buffer.compare("0x6A") == 0) {
			communicationProtocol.receive(buffer);
			if (gameName.empty()) {
				gameName = buffer;
				gamesMonitor[gameName].setPlayerTwo(player);
				buffer = gamesMonitor[gameName].toString(player);
			}

		} else if (buffer.compare("0x70") == 0) {
			if (!gameName.empty()) {
				std::string column;
				std::string row;
				communicationProtocol.receive(column, row);
				gamesMonitor[gameName].insert(stoi(row), stoi(column), player);
				buffer = gamesMonitor[gameName].toString(player);
			}
		}
		communicationProtocol.send(buffer);
		receivedBytes = communicationProtocol.receiveCommand(buffer);
	}*/
	isRunning = false;
}

void ThreadClient::stop() { }

bool ThreadClient::isDead() const {
	return !isRunning;
}