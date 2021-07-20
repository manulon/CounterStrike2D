#include "SwitchWeaponEvent.h"

SwitchWeaponEvent::SwitchWeaponEvent(short id, char weapon) : ServerEvent(id), weapon(weapon){}

void SwitchWeaponEvent::handle(Game &game){
    game.switchWeapon(id, weapon);
}