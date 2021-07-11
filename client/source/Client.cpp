#include "Client.h"
#include "EventHandler.h"

//Client::Client():events(){}

//Client::~Client(){}

void Client::run(const char * host, const char *service){
    Socket skt;
    skt.connect(host,service);
    EventHandler eh(skt);

}
