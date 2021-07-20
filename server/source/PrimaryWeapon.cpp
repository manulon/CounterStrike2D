#include "PrimaryWeapon.h"
#include "Player.h"
#include "SWeapon.h"
#include <utility>
#include <iostream>

PrimaryWeapon::PrimaryWeapon(World &world, 
							 float width, float height,
							 float maxAmmunition, short id) :
	WeaponType(width, height,id),
	world(world),
	loader(world, maxAmmunition) { } 
 
PrimaryWeapon::PrimaryWeapon(PrimaryWeapon &&other) :
	WeaponType(std::move(other)),
	world(other.world),
	loader(std::move(other.loader)) { } 

PrimaryWeapon::~PrimaryWeapon() { }

void PrimaryWeapon::collideWithPlayer(Player &player) {
	if (player.isPickingUpWeapon()){
		context->getBody()->GetFixtureList()->SetSensor(false);
        player.swapAndDropPrimaryWeapon(*this);
    }
    context->getBody()->GetFixtureList()->SetSensor(true);		
}
