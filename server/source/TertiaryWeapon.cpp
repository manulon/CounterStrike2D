#include "TertiaryWeapon.h"
#include "Player.h"
#include <utility>
#include <iostream>

TertiaryWeapon::TertiaryWeapon(float width, float height) :
	WeaponType(width, height) { }

TertiaryWeapon::TertiaryWeapon(TertiaryWeapon &&other) :
	WeaponType(std::move(other)) { }

TertiaryWeapon::~TertiaryWeapon() { }
