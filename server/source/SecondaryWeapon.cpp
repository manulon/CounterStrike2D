#include "SecondaryWeapon.h"
#include "Player.h"
#include <utility>
#include <iostream>

SecondaryWeapon::SecondaryWeapon(World &world, 
							 	 float width, float height,
							 	 float maxAmmunition, short id) :
	WeaponType(width, height, id),
	world(world),
	loader(world, maxAmmunition) { } 
 
SecondaryWeapon::SecondaryWeapon(SecondaryWeapon &&other) :
	WeaponType(std::move(other)),
	world(other.world),
	loader(std::move(other.loader)) { } 

SecondaryWeapon::~SecondaryWeapon() { }

void SecondaryWeapon::collideWithPlayer(Player &player) {
	player.swapAndDropSecondaryWeapon(*this);
}
