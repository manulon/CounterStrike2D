#ifndef _EVENT_HANDLER_H_
#define _EVENT_HANDLER_H_

#include "Soldier.h"
#include "Player.h"
#include "ClientProtocol.h"


class EventHandler {
private:
    ClientProtocol prot;
public:
    EventHandler(Socket &skt) : prot(skt){}
    ~EventHandler(){}
    bool handleEvents(Soldier &soldier, Player &player, float angle);
};



#endif