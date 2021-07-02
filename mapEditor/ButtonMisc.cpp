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

bool ButtonMisc::clicked(std::vector<Tile*>& options,const Image& image){
    for (auto& option: options){
        delete option;
        options.pop_back();
    }

    /*--- PARA AZTEC ---*/
    /*options.push_back(new Tile(5,0,500,image));
    options.push_back(new Tile(24,48,500,image));
    options.push_back(new Tile(25,98,500,image));
    options.push_back(new Tile(28,0,548,image));
    options.push_back(new Tile(29,48,548,image));
    options.push_back(new Tile(30,98,548,image));
    options.push_back(new Tile(46,146,500,image));*/

    /*--- PARA DUST ---*/
    options.push_back(new Tile(61,0,500,image));
    options.push_back(new Tile(62,48,500,image));
    options.push_back(new Tile(63,98,500,image));
    options.push_back(new Tile(65,48,548,image));
    options.push_back(new Tile(70,0,548,image));   

    return false;
}