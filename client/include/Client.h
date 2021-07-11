#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "Event.h"
#include "NonBlockingQueue.h"
#include <memory>
#include "Socket.h"

class Client {
    private:
        NonBlockingQueue<std::shared_ptr<Event>> events;
    
    public:
        Client():events(){}
        ~Client(){}
        void run(const char * host, const char *service);
};

#endif