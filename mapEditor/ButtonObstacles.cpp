#include "ButtonObstacles.h"
#include <iostream>

ButtonObstacles:: ButtonObstacles(Window& window): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Obstaculos",window),
window(window){}

ButtonObstacles::~ButtonObstacles(){}

void ButtonObstacles::render(){
    Area renderArea(544,500,100,30);
    textBox.render(renderArea);
}

bool ButtonObstacles::clicked(){
    return false;
}