#include "MouseManager.h"
#include <iostream>

int MouseManager::getPositionX(){
    return x;
}

int MouseManager::getPositionY(){
    return y;
}

int MouseManager::getAngle(){
    SDL_GetMouseState(&x, &y);
    x = x-400;
    y = 300-y;
    std::cout << "x: " << x << " y: " << y << std::endl;
    if (y != 0){
        float aux = (float)x/(float)y;
        int angle = (atan(aux)* 180 / PI);
        std::cout <<"el angulo es "<< angle << std::endl;
        if (y<0) return 180+angle;
        return angle;
    } else {
        if (x > 0) return 90;
        else return -90;
    }
    
}