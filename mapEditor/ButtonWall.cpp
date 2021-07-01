#include "ButtonWall.h"
#include <iostream>

ButtonWall:: ButtonWall(Window& window): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Paredes",window),
window(window){}

ButtonWall::~ButtonWall(){}

void ButtonWall::render(){
    Area renderArea(475,550,90,25);
    textBox.render(renderArea);
}

bool ButtonWall::clicked(){
    std::cout<<"Clickee paredes"<< std::endl;
    return false;
}