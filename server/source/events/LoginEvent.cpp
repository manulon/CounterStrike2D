#include "LoginEvent.h"

LoginEvent::LoginEvent(short id) : ServerEvent(id){}

void LoginEvent::handle(Game &game){
    game.joinPlayer(id);
}