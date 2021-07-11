#ifndef _THREAD_CLIENT_RECEIVER_
#define _THREAD_CLIENT_RECEIVER_

#include "Thread.h"
#include "Socket.h"
#include "NonBlockingQueue.h"
#include "../common/Event.h"
#include "CommunicationProtocol.h"
#include "ProtocolConstants.h"

class ThreadClientReceiver : public Thread {
    private:
        Socket& skt;
        NonBlockingQueue<std::unique_ptr<Event>>& queue;
        bool isRunning;
        
    public:
        ThreadClientReceiver(Socket &skt, NonBlockingQueue<std::unique_ptr<Event>> &queue);
        ~ThreadClientReceiver();
        virtual void run() override;
};

#endif
