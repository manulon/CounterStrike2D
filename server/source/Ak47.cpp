#include "Ak47.h"
#include "World.h"
#include <utility>

Ak47::Ak47(World &world, float width, float height) :
	PrimaryWeapon(world, width, height, 30) { }

Ak47::Ak47(Ak47 &&other) : 
	PrimaryWeapon(std::move(other)) { }

Ak47::~Ak47() { }

void Ak47::attack(float angle, float x, float y) {
    // TODO CORREGIR EXCEPCION DE EMPTY LOADER
    try {
        std::unique_ptr<Bullet> bullet(new Bullet(loader.releaseBullet()));
        bullet->shoot(angle, x, y);
        world.spawnBullet(std::move(bullet));
    } catch (...) { }
}

void Ak47::reload(size_t &ammunition) {
	loader.reload(ammunition);
}
