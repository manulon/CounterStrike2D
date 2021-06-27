#include "SdlPoint.h"
		
SdlPoint:: SdlPoint(int x, int y){
    sdlPoint = {x,y};
}

int SdlPoint:: getX() const{
    return sdlPoint.x;
}

int SdlPoint:: getY() const{
    return sdlPoint.y;
}

void SdlPoint:: setPosition(int x, int y){
    sdlPoint.x = x;
    sdlPoint.y = y;
}

SdlPoint:: ~SdlPoint(){}