#include "ButtonMisc.h"
#include <iostream>

ButtonMisc:: ButtonMisc(Window& window): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Misc",window),
window(window){}

ButtonMisc::~ButtonMisc(){}

void ButtonMisc::render(){
    Area renderArea(496,500,100,30);
    textBox.render(renderArea);
}

bool ButtonMisc::clicked(){
    return false;
}