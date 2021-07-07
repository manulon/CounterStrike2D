#include "Damage.h"

Damage::Damage():damageValue(0){}

Damage::~Damage(){}

int Damage::getDamage(){
    return damageValue;
}

void Damage::setDamage(int value){
    damageValue = value;
}
