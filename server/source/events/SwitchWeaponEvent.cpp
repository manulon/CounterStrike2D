#include "SwitchWeaponEvent.h"

SwitchWeaponEvent::SwitchWeaponEvent(short id, char weapon) : ServerEvent(id), weapon(weapon){}

void SwitchWeaponEvent::handle(Game &game){
    std::cout << "switch a arma "<<(short)weapon<<std::endl;
    game.switchWeapon(id, weapon);
}