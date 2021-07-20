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
		short id;
		WeaponType(const WeaponType &other) = delete;
		WeaponType& operator=(const WeaponType &other) = delete;
		WeaponType& operator=(WeaponType &&other) = delete;

	public:
		WeaponType(float width, float height, short id);
		WeaponType(WeaponType &&weaponType);
		virtual ~WeaponType();

		virtual void attack(float angle, float x, float y) = 0;
		virtual void reload(size_t &ammunition) = 0;
		virtual void collideWithPlayer(Player &player) = 0;
		void setContext(SWeapon *context);
		float getWidth();
		float getHeight();
		SWeapon* getContext() const;
		short getId();
};

#endif // _WEAPON_TYPE_H_
