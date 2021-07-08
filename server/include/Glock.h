#ifndef _GLOCK_H_
#define _GLOCK_H_

#include "SecondaryWeapon.h"

class Glock : public SecondaryWeapon {
	private:
		Glock(const Glock &other) = delete;
		Glock& operator=(const Glock &other) = delete;
		Glock& operator=(Glock &&other) = delete;

	public:
		Glock(World &world, float width, float height);
		Glock(Glock &&other);
		~Glock();
		void attack(float angle, float x, float y) override;
		void reload(size_t &ammunition) override;
};

#endif // _GLOCK_H_
