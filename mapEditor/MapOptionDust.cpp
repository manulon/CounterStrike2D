#include "MapOptionDust.h"
#include <iostream>

MapOptionDust:: MapOptionDust(Window& window): 
MenuOption("assets/gfx/fonts/liberationsans.ttf",40,"Dust",window),
window(window){}

MapOptionDust::~MapOptionDust(){}

const char* MapOptionDust:: getPathToImage(){
    return "assets/gfx/tiles/default_dust.png";            // Tiene que estar en YAML config
}

void MapOptionDust::render(){
    Area renderArea(300,50,100,30);
    optionText.render(renderArea);
    std::cout<<"Renderizo dust"<< std::endl;
}

bool MapOptionDust::clicked(std::vector<MenuOption*>& options){
    return true;
}
