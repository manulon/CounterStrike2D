#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "Event.h"
#include "NonBlockingQueue.h"
#include "ThreadClientReceiver.h"
#include "ThreadClientSender.h"
#include <memory>
#include "Socket.h"

class Client {
    private:
        NonBlockingQueue<std::string> nonBlockingQueue;
        BlockingQueue<std::shared_ptr<Event>> blockingQueue;
            
    public:
        Client():nonBlockingQueue(),blockingQueue(){}
        ~Client(){}
        void run(const char * host, const char *service);
};

#endif