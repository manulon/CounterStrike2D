#ifndef _LOADER_H_
#define _LOADER_H_

#include "Bullet.h"
#include <cstddef>
#include <stack>
class World;

class Loader {
	private:
		World &world;
		std::stack<Bullet> bullets;
		const size_t maxAmmunition;
		void fillLoader(size_t &ammunition);

		Loader(const Loader &other) = delete;
		Loader& operator=(const Loader &other) = delete;
		Loader& operator=(Loader &&other) = delete;

	public:
		Loader(World &world, size_t maxAmmunition);
		Loader(Loader &&other);
		~Loader();
		void reload(size_t &ammunition);
		Bullet releaseBullet();
};

#endif // _LOADER_H_
