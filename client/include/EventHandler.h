#ifndef _EVENT_HANDLER_H_
#define _EVENT_HANDLER_H_

#include "ClientProtocol.h"
#include "NonBlockingQueue.h"
#include <string>
#include "TileMap.h"

class EventHandler {
private:
    ClientProtocol protocol;
    TileMap &map;
    
public:
    EventHandler(BlockingQueue<std::shared_ptr<ClientMessage>>& queue, TileMap &map): 
                 protocol(queue), map(map) {}
    ~EventHandler(){}
    bool handleEvents();
};



#endif