#ifndef _THREAD_CLIENT_SENDER_
#define _THREAD_CLIENT_SENDER_

#include "Thread.h"
#include "Socket.h"
#include "BlockingQueue.h"
#include "../common/Event.h"
#include "CommunicationProtocol.h"
#include "ProtocolConstants.h"

class ThreadClientSender : public Thread {
    private:
        Socket &skt;
        std::shared_ptr<BlockingQueue<Event>> &queue;
        int id;
        bool isRunning;

    public:
        ThreadClientSender
        (Socket &skt, std::shared_ptr<BlockingQueue<Event>> &queue, int id);
        ~ThreadClientSender();
        
        virtual void run() override;
};

#endif