#include "ButtonBox.h"
#include <iostream>

ButtonBox:: ButtonBox(Window& window): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Cajas",window),
window(window){}

ButtonBox::~ButtonBox(){}

void ButtonBox::render(){
    Area renderArea(400,500,100,30);
    textBox.render(renderArea);
}

bool ButtonBox::clicked(){
    return false;
}