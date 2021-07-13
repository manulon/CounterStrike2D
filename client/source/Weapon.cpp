#include <iostream>
#include "Weapon.h"
#define PPM 32

Weapon::Weapon(std::string imgPath, Window &window, int width,int height) : 
DynamicObject(width,height),image(imgPath.c_str(),window){ }

Weapon::~Weapon() { }

void Weapon::render(const Area &dest){
    image.render(dest);
}

void Weapon::render(int otherX, int otherY){// other representa la pos del jugador principal
    Area dest = DynamicObject::getDest(otherX,otherY);
    image.render(dest);
}

void Weapon::render(const Area& source, const Area& dest, int angle){
    image.render(source, dest, angle, SDL_FLIP_HORIZONTAL);
}

// void Weapon::setPos(int xx, int yy){
//     x = -xx; 
//     y = -yy;
// }