#ifndef _LOADER_H_
#define _LOADER_H_

#include "Bullet.h"
#include <cstddef>
#include <list>
class World;

class Loader {
	private:
		World &world;
		std::list<Bullet> bullets;
		size_t maxAmmunition;
		
		Loader(const Loader &other) = delete;
		Loader& operator=(const Loader &other) = delete;
		Loader& operator=(Loader &&other) = delete;
		void fillLoader(size_t &ammunition);

	public:
		Loader(World &world, size_t maxAmmunition);
		Loader(Loader &&other);
		~Loader();
		Bullet releaseBullet();
		void reload(size_t &ammunition);
		//Loader& clone(const Loader &other);
};

#endif // _LOADER_H_
