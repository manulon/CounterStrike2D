#include "LoginEvent.h"

LoginEvent::LoginEvent(short id,std::string &&mapName) : ServerEvent(id), mapName(mapName){}

void LoginEvent::handle(Game &game){
    if (!game.hasStarted()){
        game.setMap(std::move(mapName));
    }
    game.joinPlayer(id);
}