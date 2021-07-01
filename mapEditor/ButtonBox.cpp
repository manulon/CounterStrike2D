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

bool ButtonBox::clicked(std::vector<Tile*>& options,const Image& image){
    for (auto& option: options){
        delete option;
        options.pop_back();
    }

    options.push_back(new Tile(21,0,500,image));
    options.push_back(new Tile(22,48,500,image));
    options.push_back(new Tile(23,98,500,image));
    options.push_back(new Tile(26,0,548,image));
    options.push_back(new Tile(27,48,548,image));
    
    return false;
}