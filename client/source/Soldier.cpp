#include "Soldier.h"
#include "Area.h"
#include <utility>
#include <iostream>
#include "SdlColor.h"

#define PPM 32

Soldier::Soldier(std::string imgPath , Window &window, int id) : 
    Animation(imgPath, window, 3, 2, PPM, 45, true),DynamicObject(PPM,PPM), 
    direction(RIGHT), moving(false),x(0),y(0), width(PPM), height(48), 
    angle(90), weaponId(-1), life(100), id(id){ }

Soldier::Soldier(std::string imgPath , Window &window) : 
    Animation(imgPath, window, 3, 2, PPM, 45, true),DynamicObject(PPM,PPM), 
    direction(RIGHT), moving(false),x(0),y(0), width(PPM), height(48), 
    angle(90), weaponId(-1), life(100), id(-1){ }    

Soldier::~Soldier() { }

void Soldier::render() {    
    Area dest((800/2)-(width/2), (600/2)-(height/2), width, height);
    Animation::render(dest, angle, SDL_FLIP_HORIZONTAL);
    
    renderActualLife();
}

void Soldier::render(int otherX, int otherY){
    Area dest = DynamicObject::getDest(otherX, otherY);
    Area src(0,18,width,height);

    dest.setWidth(width);
    dest.setHeight(height);
    
    image->render(src,dest,angle,SDL_FLIP_HORIZONTAL);    
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

void Soldier::updateInfo(float xx, float yy, short newWeaponId){
    x = xx;
    y = yy;
    this->weaponId = newWeaponId;
    changeCurrentWeapon();
}

void Soldier::setAsTerrorist(){
    image = &terroristAk47;
}
void Soldier::updateInfoo(float xx, float yy, short newWeaponId, short newAngle){
    angle = newAngle;
    weaponId = newWeaponId;
    DynamicObject::setPos(xx,yy);
    changeCurrentWeapon();
}

void Soldier::changeCurrentWeapon(){
    std::cout<<"Id del soldier y weapon id "<<id<<" "<<weaponId<<std::endl;
    
    if (id % 2 == 1){
        if (weaponId == 30){
            image = &terroristKnife;
            height = 42;
        } else if (weaponId == 11){
            image = &terroristAk47;
            height = 45;
        }
    } else {
        if (weaponId == 30){
            image = &counterTerroristKnife;
            height = 42;
        } else if (weaponId == 11){
            image = &counterTerroristAk47;
            height = 45;
        }
    }
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

void Soldier::setId(short idd){
    id = idd;
}
