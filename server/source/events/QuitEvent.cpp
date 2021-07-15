#include "QuitEvent.h"

QuitEvent::QuitEvent(short id) : ServerEvent(id){}

void QuitEvent::handle(Game &game){
    // game.removePlayer(id);
}