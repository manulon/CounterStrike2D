#include "Soldier.h"
#include "Area.h"
#include <utility>
#include <iostream>
#include "SdlColor.h"

#define PPM 32

// TODO Tal vez agregar un enum que sea
// enum {soldado_tipo_1, soldado_tipo_2, soldado_tipo3..., soldado_tipoN};
// e instanciar un objeto de una clase ImageRepository para decirle,
// imageRepository.loadImage(tipo_soldado).
// Soldado podria recibir el enum de afuera que indique el tipo de soldadito a crear
// e internamente, aca que cada enum referencie al path en donde se encuentra la
// imagen solicitada para renderizar.

Soldier::Soldier(std::string imgPath , Window &window) : 
    Animation(imgPath, window, 3, 2, PPM, 45, true),DynamicObject(PPM,PPM), 
    direction(RIGHT), moving(false),x(0),y(0), 
    width(PPM), height(45), angle(90), weaponId(-1), life(100){ }

//    Animation(imgPath, window, 3, 2, PPM, PPM, true),DynamicObject(PPM,PPM), direction(RIGHT), moving(false)
//    , width(PPM), height(PPM), angle(90), life(100), window(window),
//    currentWeapon("../assets/gfx/weapons/ak47.bmp",window,16,32) { }

// Soldier::Soldier(Soldier &&other) : 
//     Animation(std::move(other)), direction(other.direction),
//     moving(other.moving), x(other.x), y(other.y), 
//     width(other.width), height(other.height),
//     angle(other.angle), weaponId(other.weaponId) {
//     // ACA NO SERIA OTHER.direction etc etc....
//     direction = 0;
//     x = 0;
//     y = 0;
//     width = 0;
//     height = 0;
//     angle = 0;
// }



Soldier::~Soldier() { }


void Soldier::render() {
    Area dest((800/2)-(PPM/2), (600/2)-(PPM/2), width, height);
    Animation::render(dest, angle, SDL_FLIP_HORIZONTAL);
    
    renderActualLife();
}

void Soldier::render(int otherX, int otherY){
    Area dest = DynamicObject::getDest(otherX, otherY);
    Area src(0,0,width,height);
    image.render(src,dest);    
}

void Soldier::stopMoving() {
    moving = false;
}

void Soldier:: move(){
    moving = true;
}


float Soldier:: getX(){
    return x;
}

float Soldier:: getY(){
    return y;
}

int Soldier:: getAngle(){
    return angle;
}

void Soldier::setAngle(int angle){
    this->angle = angle;
}

void Soldier::updateInfo(float xx, float yy, short weaponIdd){
    // DynamicObject::setPos(xx,yy);
    x = xx;
    y = yy;
    weaponId = weaponIdd;
}

void Soldier::setAsTerrorist(){
    Image img("../assets/gfx/player/t4Ak47.png", image.getWindow());
    image = std::move(img);
}
void Soldier::updateInfoo(float xx, float yy, short weaponIdd){
    DynamicObject::setPos(xx,yy);
}

void Soldier::changeCurrentWeapon(){
    /*
    if (currentWeapon == "ak47" (o el id)){
        Image img("../assets/gfx/player/t4Knife.png", image.getWindow());
        image = std::move(img);
        height = 42;
    } else if (currentWeapon == "knife" (o el id)){
        Image img("../assets/gfx/player/t4Ak47.png", image.getWindow());
        image = std::move(img);
        height = 45;
    }
    */
}

void Soldier::renderActualLife(){
    if (life == 100)
        renderFullLife();
    else
        renderLife();
    
}

void Soldier::renderFullLife(){
    Color key = {0, 0, 0};

    Image first("../assets/gfx/fonts/lifeNumbers/1.png", window, key);
    Image second("../assets/gfx/fonts/lifeNumbers/0.png", window, key);
    Image third("../assets/gfx/fonts/lifeNumbers/0.png", window, key);

    Area lifeAreaFirst(0, window.getHeight()-PPM, 32, 40);
    Area lifeAreaSecond(20, window.getHeight()-PPM, 32, 40);
    Area lifeAreaThird(45, window.getHeight()-PPM, 32, 40);

    first.render(lifeAreaFirst);
    second.render(lifeAreaSecond);
    third.render(lifeAreaThird);
}

void Soldier::renderLife(){
    Color key = {0, 0, 0};

    int firstDigit(life/10);
    int secondDigit(life-(firstDigit*10));

    std::string firstDigitPath("../assets/gfx/fonts/lifeNumbers/"+std::to_string(firstDigit)+".png");
    std::string secondDigitPath("../assets/gfx/fonts/lifeNumbers/"+std::to_string(secondDigit)+".png");

    Image first(firstDigitPath.c_str(), window, key);
    Image second(secondDigitPath.c_str(), window, key);

    Area lifeAreaFirst(0, window.getHeight()-PPM, 32, 40);
    Area lifeAreaSecond(22, window.getHeight()-PPM, 32, 40);

    first.render(lifeAreaFirst);
    second.render(lifeAreaSecond);
}

void Soldier::setLife(short lifeNum){
    life = lifeNum;
}
