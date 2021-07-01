#include "ButtonMisc.h"
#include <iostream>

ButtonMisc:: ButtonMisc(Window& window): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Misc",window),
window(window){}

ButtonMisc::~ButtonMisc(){}

void ButtonMisc::render(){
    Area renderArea(475,515,70,25);
    textBox.render(renderArea);
}

bool ButtonMisc::clicked(){
    std::cout<<"Clickee misc"<< std::endl;
    return false;
}