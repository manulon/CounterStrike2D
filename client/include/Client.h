#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "Event.h"
#include "NonBlockingQueue.h"
#include <memory>

class Client {
    private:
        NonBlockingQueue<std::shared_ptr<Event>> events;
    
    public:
        Client():events(){}
        ~Client(){}
};

#endif