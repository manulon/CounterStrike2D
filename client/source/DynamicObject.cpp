#include "DynamicObject.h"
#define PPM 32
#include <iostream>
DynamicObject::DynamicObject(int width, int height) : 
                             x(100),y(100),width(width),height(height) {}


Area DynamicObject::getDest(int otherX, int otherY){
    int xCenter = (800/2);
    int yCenter = (600/2);
    int distX = x - otherX;
    int distY = y - otherY;
    Area dest(xCenter - distX-(PPM/2), yCenter - distY-(PPM/2), height, width);
    return dest;
}

void DynamicObject::setPos(int xx, int yy){
    std::cout << this << std::endl;
    x = -xx; y = -yy;
}

// DynamicObject& DynamicObject::operator=(DynamicObject &&other){
//     if(this == &other){
//         return *this;
//     }
//     x = other.x;
//     y = other.y ;
//     width = other.width ;
//     height = other.height ;

//     other.x = 0;
//     other.y = 0;
//     other.width = 0;
//     other.height = 0;
//     return *this;
// }
