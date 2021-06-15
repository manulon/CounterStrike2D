#include "Soldier.h"
#include "Area.h"

#include <iostream>

Soldier::Soldier(Image &image): 
an(&image,2,3), direction(RIGHT), facingLeft(false),
moving(false), x(100), y(100), height(50), width(50), angle(90)  {}

Soldier::~Soldier() {}

/**
 * Notar que el manejo de eventos y la actualización de modelo ocurren en momentos distintos.
 * Esto les va a resultar muy util en un juego multiplaforma. 
 */
void Soldier::update(float dt) {
    if (moving) {
        an.update(dt);
        if (direction == LEFT) {
            angle = -90;
            x -= 3;
        }else if (direction == RIGHT) {
            angle = 90;
            x += 3;
        }else if (direction == UP) {
            angle = 0;
            y -= 3;
        }else if (direction == DOWN) {
            angle = -180;
            y += 3;
        }else if (direction == DOWN_LEFT){
            angle = -135;
            y += 3;
            x -= 3;
        }else if (direction == DOWN_RIGHT){
            angle = 135;
            y += 3;
            x += 3;
        }else if (direction == UP_RIGHT){
            angle = 45;
            y -= 3;
            x += 3;
        }else if (direction == UP_LEFT){
            angle = -45;
            y -= 3;
            x -= 3;
        }
    }
}

void Soldier::render() {
    Area dest(x, y, height, width);
    SDL_RendererFlip flip = facingLeft ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
    an.render(dest, flip, angle);
}

void Soldier::stopMoving() {
    moving = false;
}

void Soldier:: clear(){
    an.clear();
}
void Soldier:: move(char dir){
    moving = true;
    direction = dir;
}

void Soldier:: stopLeft(){
    if (direction == DOWN_LEFT) direction = DOWN;
    else if (direction == UP_LEFT) direction = UP;
    else if (direction == LEFT) stopMoving();
}
void Soldier:: stopRight(){
    if (direction == DOWN_RIGHT) direction = DOWN;
    else if (direction == UP_RIGHT) direction = UP;
    else if (direction == RIGHT) stopMoving();
}
void Soldier:: stopUp(){
    if (direction == UP_RIGHT) direction = RIGHT;
    else if (direction == UP_LEFT) direction = LEFT;
    else if (direction == UP) stopMoving();
}
void Soldier:: stopDown(){
    if (direction == DOWN_RIGHT) direction = RIGHT;
    else if (direction == DOWN_LEFT) direction = LEFT;
    else if (direction == DOWN) stopMoving();
}