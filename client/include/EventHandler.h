#ifndef _EVENT_HANDLER_H_
#define _EVENT_HANDLER_H_
#include "Soldier.h"
#include "Player.h"


class EventHandler {
private:
    //ClientProtocol &prot; con quien interactua el cliente
public:
    EventHandler(/* args */){}
    ~EventHandler(){}
    bool handleEvents(Soldier &soldier, Player &player, float angle);
};



#endif