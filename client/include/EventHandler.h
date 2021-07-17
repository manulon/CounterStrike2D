#ifndef _EVENT_HANDLER_H_
#define _EVENT_HANDLER_H_

#include "Soldier.h"
#include "Player.h"
#include "ClientProtocol.h"
#include "NonBlockingQueue.h"
#include <string>

class EventHandler {
private:
    ClientProtocol protocol;
    
public:
    EventHandler(Socket &skt,BlockingQueue<std::shared_ptr<ClientMessage>>& queue): 
                 protocol(skt,queue) {}
    ~EventHandler(){}
    bool handleEvents();
};



#endif