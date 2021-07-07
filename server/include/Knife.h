#ifndef _KINFE_H_
#define _KINFE_H_

#include "TertiaryWeapon.h"
#include "Damage.h"

class Knife : public TertiaryWeapon {
	private:
		Knife(const Knife &other) = delete;
		Knife& operator=(const Knife &other) = delete;
		Knife& operator=(Knife &&other) = delete;

		/*El damage deberia setearse del config.yaml*/
		Damage damage;

	public:
		Knife(float width, float height);
		Knife(Knife &&other);
		~Knife();
		void attack(float angle, float x, float y) override;
		virtual void collideWithPlayer(Player &player) override;
		void reload(size_t &ammunition) override;
};

#endif // _KINFE_H_
