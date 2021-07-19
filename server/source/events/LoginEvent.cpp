#include "LoginEvent.h"

LoginEvent::LoginEvent(short id,std::string &&mapName) : ServerEvent(id), mapName(mapName){}

void LoginEvent::handle(Game &game){
    std::cout<<"mapa: "<<mapName<<std::endl;
    game.joinPlayer(id);
}