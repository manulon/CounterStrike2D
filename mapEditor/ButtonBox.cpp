#include "ButtonBox.h"
#include <iostream>

ButtonBox:: ButtonBox(Window& window): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Cajas",window),
window(window){}

ButtonBox::~ButtonBox(){}

void ButtonBox::render(){
    Area renderArea(475,485,70,25);
    textBox.render(renderArea);
}

bool ButtonBox::clicked(std::vector<Button*> buttons){
    std::cout<<"Clickee cajas"<< std::endl;
    
    return false;
}