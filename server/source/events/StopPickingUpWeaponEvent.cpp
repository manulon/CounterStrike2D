#include "StopPickingUpWeaponEvent.h"

StopPickingUpWeaponEvent::StopPickingUpWeaponEvent(short id) : ServerEvent(id){}

void StopPickingUpWeaponEvent::handle(Game &game){
    game.stopPickingUpWeapon(id);
}