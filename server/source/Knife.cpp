#include "Knife.h"
#include "SWeapon.h"
#include <utility>
#include <cmath>
#include <iostream>

Knife::Knife(float width, float height) : 
	TertiaryWeapon(width, height, 30), damage(50) { }

Knife::Knife(Knife &&other) : 
	TertiaryWeapon(std::move(other)), damage(50) {
}

Knife::~Knife() { }

void Knife::attack(float angle, float x, float y) {
    float radians = (angle * M_PI) / 180.0f;
    float radius = sqrt(pow(getWidth(), 2) + pow(getHeight(), 2));
    SWeapon *context = WeaponType::getContext();
    std::cout << x + radius*cos(radians)*2 << std::endl;
    context->earlyAttachToWorld(x + radius*cos(radians)*2, 
                                y + radius*sin(radians)*2);
    context->detachFromWorld();
    std::cout<<"Sale de cuchi attack"<<std::endl;
}

void Knife::reload(size_t &ammunition) { 
    // Lanzar excepcion a lo sumo
}

void Knife::collideWithPlayer(Player &player) {
    player.decreaseLife(damage.getDamage());
}
