#ifndef _WEAPON_TYPE_H_
#define _WEAPON_TYPE_H_

#include "Player.h"
#include <cstddef>
class SWeapon;


class WeaponType {
	private:
		SWeapon *context;
		float width;
		float height;

		WeaponType(const WeaponType &other) = delete;
		WeaponType& operator=(const WeaponType &other) = delete;
		WeaponType& operator=(WeaponType &&other) = delete;

	public:
		WeaponType(float width, float height);
		WeaponType(WeaponType &&weaponType);
		virtual ~WeaponType();

		virtual void attack(float angle, float x, float y) = 0;
		virtual void reload(size_t &ammunition) = 0;
		virtual void collideWithPlayer(Player &player) = 0;
		void setContext(SWeapon *context);
		float getWidth();
		float getHeight();
		SWeapon* getContext() const;
};

#endif // _WEAPON_TYPE_H_
