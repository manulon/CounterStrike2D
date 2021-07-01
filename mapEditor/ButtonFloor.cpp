#include "ButtonFloor.h"
#include <iostream>

ButtonFloor:: ButtonFloor(Window& window): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Pisos",window),
window(window){}

ButtonFloor::~ButtonFloor(){}

void ButtonFloor::render(){
    Area renderArea(448,500,100,30);
    textBox.render(renderArea);
}

bool ButtonFloor::clicked(){
    return false;
}