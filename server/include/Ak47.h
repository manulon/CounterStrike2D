#ifndef _AK47_H_
#define _AK47_H_

#include "PrimaryWeapon.h"

class Ak47 : public PrimaryWeapon {
	private:
		Ak47(const Ak47 &other) = delete;
		Ak47& operator=(const Ak47 &other) = delete;
		Ak47& operator=(Ak47 &&other) = delete;

	public:
		Ak47(World &world, float width, float height);
		Ak47(Ak47 &&other);
		~Ak47();
		void attack(float angle, float x, float y) override;
		void reload(size_t &ammunition) override;


};

#endif // _AK47_H_
