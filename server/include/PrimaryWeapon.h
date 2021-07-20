#ifndef _PRIMARY_WEAPON_H_
#define _PRIMARY_WEAPON_H_

#include "WeaponType.h"
#include "Loader.h"
class World;

class PrimaryWeapon : public WeaponType {
	private:
		PrimaryWeapon(const PrimaryWeapon &other) = delete;
		PrimaryWeapon& operator=(const PrimaryWeapon &other) = delete;
		PrimaryWeapon& operator=(PrimaryWeapon &&other) = delete;

	protected:
		World &world;
		Loader loader;

	public:
		PrimaryWeapon(World &world, 
					  float width, float height,
					  float maxAmmunition, short id);
		PrimaryWeapon(PrimaryWeapon &&other);
		virtual ~PrimaryWeapon(); 

		void collideWithPlayer(Player &player) override;
		virtual void attack(float angle, float x, float y) = 0;
		virtual void reload(size_t &ammunition) = 0;
};

#endif // _PRIMARY_WEAPON_H_
