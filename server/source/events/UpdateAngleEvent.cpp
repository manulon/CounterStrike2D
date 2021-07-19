#include "UpdateAngleEvent.h"

UpdateAngleEvent::UpdateAngleEvent(short id, short arg): 
ServerEvent(id), arg(arg){}

void UpdateAngleEvent::handle(Game &game){
    game.setPlayerAngle(id,arg);
}