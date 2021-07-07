#include "Knife.h"
#include "SWeapon.h"
#include <utility>
#include <cmath>
#include <iostream>

Knife::Knife(float width, float height) : 
	TertiaryWeapon(width, height) { }

Knife::Knife(Knife &&other) : 
	TertiaryWeapon(std::move(other)) {
}

Knife::~Knife() { }

void Knife::attack(float angle, float x, float y) {
    //std::cout << "Entro a atacar con cuchillo" << std::endl;
    float radians = (angle * M_PI) / 180.0f;
    float radius = sqrt(pow(getWidth(), 2) + pow(getHeight(), 2));
    SWeapon *context = WeaponType::getContext();
    std::cout << x + radius*cos(radians)*2 << std::endl;
    context->earlyAttachToWorld(x + radius*cos(radians)*2, 
                                y + radius*sin(radians)*2);
    context->detachFromWorld();
}

void Knife::reload(size_t &ammunition) { 
    // Lanzar excepcion a lo sumo
}
//earlyAttachToWorld(x + radius*cos(radians)*2, 
//      	           y + radius*sin(radians)*2);
//Entity::detachFromWorld();