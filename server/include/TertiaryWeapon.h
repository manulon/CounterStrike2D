#ifndef _TERTIARY_WEAPON_H_
#define _TERTIARY_WEAPON_H_

#include "WeaponType.h"

class TertiaryWeapon : public WeaponType {
	private:
		TertiaryWeapon(const TertiaryWeapon &other) = delete;
		TertiaryWeapon& operator=(const TertiaryWeapon &other) = delete;
		TertiaryWeapon& operator=(TertiaryWeapon &&other) = delete;

	public:
		TertiaryWeapon(float width, float height);
		TertiaryWeapon(TertiaryWeapon &&other);
		virtual ~TertiaryWeapon();

		virtual void collideWithPlayer(Player &player) = 0;
		virtual void attack(float angle, float x, float y) = 0;
		virtual void reload(size_t &ammunition) = 0;
};

#endif // _TERTIARY_WEAPON_H_
