#include "ButtonObstacles.h"
#include <iostream>

ButtonObstacles:: ButtonObstacles(Window& window): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Obstaculos",window),
window(window){}

ButtonObstacles::~ButtonObstacles(){}

void ButtonObstacles::render(){
    Area renderArea(600,515,125,25);
    textBox.render(renderArea);
}

bool ButtonObstacles::clicked(){
    std::cout<<"Clickee obstaculos"<< std::endl;
    return false;
}