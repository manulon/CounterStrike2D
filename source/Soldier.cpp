#include "Soldier.h"
#include "Area.h"
#include <utility>

// TODO Tal vez agregar un enum que sea
// enum {soldado_tipo_1, soldado_tipo_2, soldado_tipo3..., soldado_tipoN};
// e instanciar un objeto de una clase ImageRepository para decirle,
// imageRepository.loadImage(tipo_soldado).
// Soldado podria recibir el enum de afuera que indique el tipo de soldadito a crear
// e internamente, aca que cada enum referencie al path en donde se encuentra la
// imagen solicitada para renderizar.

Soldier::Soldier(const Image &image) : 
    Animation(image, 3, 2, 32, 32, true), direction(RIGHT), moving(false),
    x(100), y(100), width(32), height(32), angle(90) { }

Soldier::Soldier(Soldier &&other) : 
    Animation(std::move(other)), direction(other.direction),
    moving(other.moving), x(other.x), y(other.y), 
    width(other.width), height(other.height),
    angle(other.angle) {
    // ACA NO SERIA OTHER.direction etc etc....
    direction = 0;
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    angle = 0;
}

Soldier::~Soldier() { }

void Soldier::update(float dt) {
    if (moving) {
        Animation::update(dt);
    }
}

void Soldier::render() {
    // Area dest((800/2)-(32/2), (600/2)-(32/2), height, width);
    Area dest((800/2)-(32/2), (600/2)-(32/2), height, width);
    Animation::render(dest, angle, SDL_FLIP_HORIZONTAL);
}

void Soldier::stopMoving() {
    moving = false;
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

int Soldier:: getX(){
    return x;
}

int Soldier:: getY(){
    return y;
}

int Soldier:: getAngle(){
    return angle;
}

void Soldier::setAngle(int angle){
    this->angle = angle;
}