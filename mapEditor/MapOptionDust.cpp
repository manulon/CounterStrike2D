#include "MapOptionDust.h"
#include <iostream>

MapOptionDust:: MapOptionDust(Window& window): 
MenuOption("assets/gfx/buttons/ButtonDust.png",window,250,25,239,32),
window(window){}

MapOptionDust::~MapOptionDust(){}

const char* MapOptionDust:: getPathToImage(){
    return "assets/gfx/tiles/default_dust.png";            // Tiene que estar en YAML config
}

const char* MapOptionDust::getMapName(){
    return "dust";
}

void MapOptionDust::render(){
    button.render(buttonArea);
}

bool MapOptionDust::clicked(std::vector<MenuOption*>& options){
    return false;
}

void MapOptionDust::setPair(std::pair<int,int>& pair){}

bool MapOptionDust::mouseInButton(int x, int y){
    if ( (x > buttonArea.getX() && x < (buttonArea.getX() + buttonArea.getWidth()) &&
         (y > buttonArea.getY() && y < (buttonArea.getY() + buttonArea.getHeight())) )) {
         return true;
    }
    return false;
}