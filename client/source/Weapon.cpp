#include <iostream>
#include "Weapon.h"
#define PPM 32

Weapon::Weapon(std::string imgPath, Window &window, int width,int height) : DynamicObject(width,height),image(imgPath.c_str(),window){ }

Weapon::~Weapon() { }


void Weapon::render(int otherX, int otherY){// other representa la pos del jugador principal
    Area dest = DynamicObject::getDest(otherX,otherY);
    image.render(dest);
}

// void Weapon::setPos(int xx, int yy){
//     x = -xx; 
//     y = -yy;
// }