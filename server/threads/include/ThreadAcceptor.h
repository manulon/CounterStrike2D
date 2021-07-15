#ifndef _THREAD_ACCEPTOR_H_
#define _THREAD_ACCEPTOR_H_
#include "Clients.h"
#include "Socket.h"
#include "Thread.h"
#include "ThreadServerReceiver.h"
#include "ThreadServerSender.h"
#include <map>

class ThreadAcceptor : public Thread {
	private:
		Socket acceptor;
		bool isRunning;
		NonBlockingQueue<std::shared_ptr<ServerEvent>> &queue;
		std::map<short,std::shared_ptr<BlockingQueue<ServerMessage*>>> &senderQueues;
		std::map<short,std::tuple<Socket,ThreadServerReceiver*,ThreadServerSender*>> clients;

		ThreadAcceptor(const ThreadAcceptor &other) = delete;
		ThreadAcceptor& operator=(const ThreadAcceptor &other) = delete;
		void cleanDeadClients();
		void run() override;

	public:
		ThreadAcceptor(const char *host, const char *service,
					   NonBlockingQueue<std::shared_ptr<ServerEvent>> &queue, 
					   std::map<short,std::shared_ptr<BlockingQueue<ServerMessage*>>> & senderQueues);
		ThreadAcceptor(ThreadAcceptor &&other);
		~ThreadAcceptor();
		ThreadAcceptor& operator=(ThreadAcceptor &&other);
		void stop();
};

#endif // _THREAD_ACCEPTOR_H_
