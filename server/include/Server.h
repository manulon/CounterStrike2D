#ifndef _SERVER_H_
#define _SERVER_H_
#include "ThreadAcceptor.h"
class Server {
private:
    NonBlockingQueue<std::shared_ptr<Event>> clientEvents;
    std::map<short,ServerMessage*> clientQueues;

public:
    Server(){}
    ~Server(){}
    void run(const char* host, const char* service);
};



#endif