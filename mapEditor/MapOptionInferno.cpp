#include "MapOptionInferno.h"
#include <iostream>

MapOptionInferno:: MapOptionInferno(Window& window): 
MenuOption("assets/gfx/fonts/liberationsans.ttf",40,"Inferno",window),
window(window){}

MapOptionInferno::~MapOptionInferno(){}

const char* MapOptionInferno:: getPathToImage(){
    return "assets/gfx/tiles/default_inferno.png";            // Tiene que estar en YAML config
}

const char* MapOptionInferno::getMapName(){
    return "inferno";
}

void MapOptionInferno::render(){
    Area renderArea(300,75,100,30);
    optionText.render(renderArea);
    
}

bool MapOptionInferno::clicked(std::vector<MenuOption*>& options){
    return false;
}

void MapOptionInferno::setPair(std::pair<int,int>& pair){}
