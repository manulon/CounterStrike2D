#include "Server.h"

void Server::run(const char* host, const char* service){
    ThreadAcceptor acceptor(host, service, clientEvents);
    acceptor.spawn();
    std::string input("");
    while (input != "q"){
        std::cin >> input;
    }
    acceptor.stop();
}