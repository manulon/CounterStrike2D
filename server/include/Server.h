#ifndef _SERVER_H_
#define _SERVER_H_
#include "ThreadAcceptor.h"
class Server {
private:
    NonBlockingQueue<std::unique_ptr<ClientEvent>> clientEvents;
public:
    Server(/* args */);
    ~Server();
};

Server::Server(/* args */)
{
}

Server::~Server()
{
}


#endif