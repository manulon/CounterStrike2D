#include "MouseManager.h"
#include <iostream>


MouseManager::MouseManager(int windowWidth, int windowHeight) : 
                        windowWidth(windowWidth), windowHeight(windowHeight){}
int MouseManager::getPositionX(){
    SDL_GetMouseState(&x, &y);
    return x;
}

int MouseManager::getPositionY(){
    SDL_GetMouseState(&x, &y);
    return y;
}

void MouseManager::update(){
    SDL_GetMouseState(&x, &y);
}

int MouseManager::getAngle(){
    SDL_GetMouseState(&x, &y);
    std::cout<<"mouse x: "<<x<<" y: "<<y<<std::endl;
    int xAux = x-(windowWidth/2);
    int yAux = (windowHeight/2)-y;
    if (yAux != 0){
        float aux = (float)xAux/(float)yAux;
        int angle = (atan(aux)* 180 / PI);
        if (yAux < 0) {
            std::cout<<"ONDETA 1\n";
            return 180 + angle;
        }
        std::cout<<"ONDETA 2\n";
        return angle;
    } else {
        if (xAux > 0) {
            std::cout<<"ONDETA 3\n";
            return 90;
        }
        else{
            std::cout<<"ONDETA 4\n";
            return -90;
        } 
    }
}