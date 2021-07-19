#include "PickUpWeaponEvent.h"

PickUpWeaponEvent::PickUpWeaponEvent(short id) : ServerEvent(id){}

void PickUpWeaponEvent::handle(Game &game){
    game.pickUpWeapon(id);
}