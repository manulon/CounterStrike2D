#include "SecondaryWeapon.h"
#include "Player.h"
#include <utility>
#include <iostream>

SecondaryWeapon::SecondaryWeapon(World &world, 
							 	 float width, float height,
							 	 float maxAmmunition) :
	WeaponType(width, height),
	world(world),
	loader(world, maxAmmunition) { } 
 
SecondaryWeapon::SecondaryWeapon(SecondaryWeapon &&other) :
	WeaponType(std::move(other)),
	world(other.world),
	loader(std::move(other.loader)) { } 

SecondaryWeapon::~SecondaryWeapon() { }

void SecondaryWeapon::collideWithPlayer(Player &player) {
	std::cout << "SecondaryWeapon choco con player" << std::endl;
	player.swapAndDropSecondaryWeapon(*this);
}
