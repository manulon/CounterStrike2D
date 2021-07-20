#include "TertiaryWeapon.h"
#include "Player.h"
#include <utility>
#include <iostream>

TertiaryWeapon::TertiaryWeapon(float width, float height, short id) :
	WeaponType(width, height,id) { }

TertiaryWeapon::TertiaryWeapon(TertiaryWeapon &&other) :
	WeaponType(std::move(other)) { }

TertiaryWeapon::~TertiaryWeapon() { }
