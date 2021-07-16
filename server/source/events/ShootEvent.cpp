#include "ShootEvent.h"

ShootEvent::ShootEvent(short id, int angle) : ServerEvent(id), angle(angle){}

void ShootEvent::handle(Game &game) {
    game.shoot(id, angle);
    std::cout << "ocurrio algo en ShootEvent\n";
}