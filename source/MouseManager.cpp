#include "MouseManager.h"
#include <iostream>


MouseManager::MouseManager(int windowWidth, int windowHeight) : 
                        windowWidth(windowWidth), windowHeight(windowHeight){}
int MouseManager::getPositionX(){
    return x;
}

int MouseManager::getPositionY(){
    return y;
}

void MouseManager::update(){
    SDL_GetMouseState(&x, &y);
}

int MouseManager::getAngle(){
    // SDL_GetMouseState(&x, &y);
    int xAux = x-(windowWidth/2);
    int yAux = (windowHeight/2)-y;
    if (yAux != 0){
        float aux = (float)xAux/(float)yAux;
        int angle = (atan(aux)* 180 / PI);
        if (yAux < 0) return 180 + angle;
        return angle;
    } else {
        if (xAux > 0) return 90;
        else return -90;
    }
    
}