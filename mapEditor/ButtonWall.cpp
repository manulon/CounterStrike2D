#include "ButtonWall.h"
#include <iostream>

ButtonWall:: ButtonWall(Window& window): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Paredes",window),
window(window){}

ButtonWall::~ButtonWall(){}

void ButtonWall::render(){
    Area renderArea(592,500,100,30);
    textBox.render(renderArea);
}

bool ButtonWall::clicked(){
    return false;
}