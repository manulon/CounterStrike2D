#include "ButtonWall.h"
#include <iostream>

ButtonWall:: ButtonWall(Window& window): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Paredes",window),
window(window){}

ButtonWall::~ButtonWall(){}

void ButtonWall::render(){
    Area renderArea(475,550,90,25);
    textBox.render(renderArea);
}

bool ButtonWall::clicked(std::vector<Tile*>& options,const Image& image){
    for (auto& option: options){
        delete option;
        options.pop_back();
    }
    
    /*--- PARA AZTEC ---*/
    /*options.push_back(new Tile(7,0,500,image));
    options.push_back(new Tile(11,0,548,image));
    options.push_back(new Tile(8,48,500,image));
    options.push_back(new Tile(12,48,548,image));
    options.push_back(new Tile(9,98,500,image));   
    options.push_back(new Tile(13,98,548,image));
    options.push_back(new Tile(14,146,500,image));
    options.push_back(new Tile(16,146,548,image));
    options.push_back(new Tile(17,194,548,image));
    options.push_back(new Tile(18,194,500,image));
    options.push_back(new Tile(19,242,500,image));*/

    /*--- PARA DUST ---*/
    options.push_back(new Tile(3,0,500,image));
    options.push_back(new Tile(4,0,548,image));
    options.push_back(new Tile(5,48,500,image));
    options.push_back(new Tile(38,48,548,image));
    options.push_back(new Tile(39,98,500,image));   
    options.push_back(new Tile(43,98,548,image));
    options.push_back(new Tile(44,146,500,image));

    return false;
}