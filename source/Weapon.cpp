#include "Weapon.h"
#define PPM 32

Weapon::Weapon(const Image &image,int width,int height) : DynamicObject(width,height),image(image){ }

Weapon::~Weapon() { }


void Weapon::render(int otherX, int otherY){// other representa la pos del jugador principal
    Area dest = DynamicObject::getDest(otherX,otherY);
    image.render(dest);
}

// void Weapon::setPos(int xx, int yy){
//     x = -xx; 
//     y = -yy;
// }