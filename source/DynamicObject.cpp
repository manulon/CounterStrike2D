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
    x = -xx; y = -yy;
}