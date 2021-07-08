#ifndef _SECONDARY_WEAPON_H_
#define _SECONDARY_WEAPON_H_

#include "WeaponType.h"
#include "Loader.h"
class World;

class SecondaryWeapon : public WeaponType {
	private:
		SecondaryWeapon(const SecondaryWeapon &other) = delete;
		SecondaryWeapon& operator=(const SecondaryWeapon &other) = delete;
		SecondaryWeapon& operator=(SecondaryWeapon &&other) = delete;

	protected:
		World &world;
		Loader loader;

	public:
		SecondaryWeapon(World &world, 
					  	float width, float height,
					  	float maxAmmunition);
		SecondaryWeapon(SecondaryWeapon &&other);
		virtual ~SecondaryWeapon(); 

		void collideWithPlayer(Player &player) override;
		virtual void attack(float angle, float x, float y) = 0;
		virtual void reload(size_t &ammunition) = 0;
};

#endif // _SECONDARY_WEAPON_H_