#include "Soldier.h"
#include "Area.h"

#include <iostream>

Soldier::Soldier(Image &image): 
an(&image,2,3), facingLeft(false), facingRight(true), facingUp(false),
moving(false), x(100), y(100), height(50), width(50), angle(90) {}

Soldier::~Soldier() {}

/**
 * Notar que el manejo de eventos y la actualización de modelo ocurren en momentos distintos.
 * Esto les va a resultar muy util en un juego multiplaforma. 
 */
void Soldier::update(float dt) {
    if (moving) {
        an.update(dt);
        if (facingLeft){
            angle = -90;
            x -= 3;
        }else if (facingRight){
            angle = 90;
            x += 3;
        }else if (facingUp){
            angle = 0;
            y -= 3;
        }else{
            angle = -180;
            y += 3;
        }
    }
}

void Soldier::render() {
    Area dest(x, y, height, width);
    SDL_RendererFlip flip = facingLeft ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
    an.render(dest, flip, angle);
}

void Soldier::moveRigth() {
    moving = true;
    facingLeft = false;
}

void Soldier::moveLeft() {
    moving = true;
    facingLeft = true;
}

void Soldier::moveUp() {
    moving = true;
    facingUp = true;
}

void Soldier::moveDown() {
    moving = true;
    facingLeft = false;
    facingRight = false;
    facingUp = false;
}

void Soldier::stopMoving() {
    moving = false;
}

void Soldier:: clear(){
    an.clear();
}
