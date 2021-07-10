#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "BlockingQueue.h"
#include "ThreadServerReceiver"
#include "ThreadServerSender.h"

class Client {
	private: 
		BlockingQueue messagesToClient;
		ThreadServerReceiver receiver;
		ThreadServerSender sender;

	public:
		Client();
		~Client();

		void run();

};

#endif // _CLIENT_H_
