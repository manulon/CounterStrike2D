#include "PrimaryWeapon.h"
#include "Player.h"
#include <utility>
#include <iostream>

PrimaryWeapon::PrimaryWeapon(World &world, 
							 float width, float height,
							 float maxAmmunition) :
	WeaponType(width, height),
	world(world),
	loader(world, maxAmmunition) { } 
 
PrimaryWeapon::PrimaryWeapon(PrimaryWeapon &&other) :
	WeaponType(std::move(other)),
	world(other.world),
	loader(std::move(other.loader)) { } 

PrimaryWeapon::~PrimaryWeapon() { }


void PrimaryWeapon::collideWithPlayer(Player &player) {
	std::cout << "PrimaryWeapon choco con player" << std::endl;
	player.collideWithPrimaryWeapon(*this);
}
