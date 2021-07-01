#include "ButtonFloor.h"
#include <iostream>

ButtonFloor:: ButtonFloor(Window& window): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Pisos",window),
window(window){}

ButtonFloor::~ButtonFloor(){}

void ButtonFloor::render(){
    Area renderArea(600,485,70,25);
    textBox.render(renderArea);
}

bool ButtonFloor::clicked(){
    std::cout<<"Clickee pisos"<< std::endl;
    return false;
}