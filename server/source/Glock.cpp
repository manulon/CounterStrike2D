#include "Glock.h"
#include "World.h"
#include <utility>

Glock::Glock(World &world, float width, float height) :
	SecondaryWeapon(world, width, height, 20, 20) { }

Glock::Glock(Glock &&other) : 
	SecondaryWeapon(std::move(other)) { }

Glock::~Glock() { }

void Glock::attack(float angle, float x, float y) {
    // TODO CORREGIR EXCEPCION DE EMPTY LOADER
    try {
        std::shared_ptr<Bullet> bullet(new Bullet(loader.releaseBullet()));
        bullet->shoot(angle, x, y);
        bullet->setDamage(15);
        world.spawnBullet(std::move(bullet));
    } catch (...) { }
}

void Glock::reload(size_t &ammunition) {
	loader.reload(ammunition);
}
