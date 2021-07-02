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

    /*--- PARA AZTEC ---*/
    /*options.push_back(new Tile(21,0,500,image));
    options.push_back(new Tile(22,48,500,image));
    options.push_back(new Tile(23,98,500,image));
    options.push_back(new Tile(26,0,548,image));
    options.push_back(new Tile(27,48,548,image));*/

    /*--- PARA DUST ---*/
    options.push_back(new Tile(21,0,500,image));
    options.push_back(new Tile(22,0,548,image));
    options.push_back(new Tile(23,48,500,image));
    options.push_back(new Tile(24,48,548,image));
    options.push_back(new Tile(25,98,500,image));   
    options.push_back(new Tile(26,98,548,image));
    options.push_back(new Tile(27,146,500,image));
    options.push_back(new Tile(28,146,548,image));
    options.push_back(new Tile(29,194,548,image));
    options.push_back(new Tile(30,194,500,image));
    
    return false;
}