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

bool ButtonFloor::clicked
(std::vector<Tile*>& options, const Image& image){
    for (auto& option: options){
        delete option;
        options.pop_back();
    }

    options.push_back(new Tile(2,0,500,image));
    options.push_back(new Tile(3,48,500,image));
    options.push_back(new Tile(4,98,500,image));
    options.push_back(new Tile(38,148,500,image));
    options.push_back(new Tile(39,0,548,image));
    options.push_back(new Tile(43,48,548,image));
    options.push_back(new Tile(44,98,548,image));

    return false;
}