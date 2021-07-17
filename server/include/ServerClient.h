#ifndef _SERVER_CLIENT_H_
#define _SERVER_CLIENT_H_

#include "BlockingQueue.h"
#include "ThreadServerReceiver.h"
#include "ThreadServerSender.h"

class ServerClient {
	private: 
		/*std::string esta bien???*/BlockingQueue<int> messagesToClient;
		/*ThreadServerReceiver receiver;
		ThreadServerSender sender;*/

	public:
		ServerClient();
		~ServerClient();

		void run();

};

#endif // _CLIENT_H_
