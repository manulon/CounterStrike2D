#include "ShootEvent.h"

ShootEvent::ShootEvent(short id, short angle) : ServerEvent(id), angle(angle){}

void ShootEvent::handle(Game &game) {
    game.shoot(id, angle);
}