#include "TertiaryWeapon.h"
#include "Player.h"
#include <utility>
#include <iostream>

TertiaryWeapon::TertiaryWeapon(float width, float height) :
	WeaponType(width, height) { }

TertiaryWeapon::TertiaryWeapon(TertiaryWeapon &&other) :
	WeaponType(std::move(other)) { }

TertiaryWeapon::~TertiaryWeapon() { }

void TertiaryWeapon::collideWithPlayer(Player &player) {
	std::cout << "TertiaryWeapon choco con player" << std::endl;
	player.swapAndDropTertiaryWeapon(*this);
}
