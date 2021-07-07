#ifndef _KINFE_H_
#define _KINFE_H_

#include "TertiaryWeapon.h"

class Knife : public TertiaryWeapon {
	private:
		Knife(const Knife &other) = delete;
		Knife& operator=(const Knife &other) = delete;
		Knife& operator=(Knife &&other) = delete;

	public:
		Knife(float width, float height);
		Knife(Knife &&other);
		~Knife();
		void attack(float angle, float x, float y) override;
		void reload(size_t &ammunition) override;
};

#endif // _KINFE_H_
