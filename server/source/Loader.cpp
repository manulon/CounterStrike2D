#include "Loader.h"
#include "World.h"

Loader::Loader(World &world, size_t maxAmmunition) : 
	world(world), maxAmmunition(maxAmmunition) {
	fillLoader(maxAmmunition);
}

Loader::Loader(Loader &&other) : 
	world(other.world),
	bullets(std::move(other.bullets)),
	maxAmmunition(other.maxAmmunition) { }

Loader::~Loader() { }

void Loader::reload(size_t &ammunition) {
	size_t counter = bullets.size();
	size_t toLoad = maxAmmunition - counter;
	if (toLoad <= ammunition) {
		fillLoader(toLoad);
		ammunition -= toLoad;
	} else {
		fillLoader(ammunition);
		ammunition = 0;
	}
}

Bullet Loader::releaseBullet() {
	if (bullets.empty()) {
		//TODO LUEGO ARREGLAR LA EXCEPCION
		throw "Out of bullets";
	}
	Bullet bullet = std::move(bullets.back());
	bullets.pop_back();
	return bullet;
}

void Loader::fillLoader(size_t &ammunition) {
	for (size_t i = 0; i < ammunition; ++i) {
		bullets.push_front(Bullet(world));
	}
}
