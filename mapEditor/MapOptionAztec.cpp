#include "MapOptionAztec.h"
#include <iostream>
#include <unistd.h>


MapOptionAztec:: MapOptionAztec(Window& window): 
MenuOption("assets/gfx/fonts/liberationsans.ttf",40,"Aztec",window),
window(window){}

MapOptionAztec::~MapOptionAztec(){}

const char* MapOptionAztec:: getPathToImage(){
    return "assets/gfx/tiles/default_aztec.png";            // Tiene que estar en YAML config
}

void MapOptionAztec::render(){
    Area renderArea(300,25,100,30);
    optionText.render(renderArea);
    std::cout<<"Renderizo aztec"<< std::endl;
}

bool MapOptionAztec::clicked(std::vector<MenuOption*>& options){
    return true;
}
