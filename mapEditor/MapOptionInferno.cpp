#include "MapOptionInferno.h"
#include <iostream>

MapOptionInferno:: MapOptionInferno(Window& window): 
MenuOption("assets/gfx/buttons/ButtonInferno.png",window,250,95,239,32),
window(window){}

MapOptionInferno::~MapOptionInferno(){}

const char* MapOptionInferno:: getPathToImage(){
    return "assets/gfx/tiles/default_inferno.png";            // Tiene que estar en YAML config
}

const char* MapOptionInferno::getMapName(){
    return "inferno";
}

void MapOptionInferno::render(){
    button.render(buttonArea);
    
}

bool MapOptionInferno::clicked(std::vector<MenuOption*>& options){
    return false;
}

void MapOptionInferno::setPair(std::pair<int,int>& pair){}

bool MapOptionInferno::mouseInButton(int x, int y){
   if ( (x > buttonArea.getX() && x < (buttonArea.getX() + buttonArea.getWidth()) &&
         (y > buttonArea.getY() && y < (buttonArea.getY() + buttonArea.getHeight())) )) {
         return true;
    }
    return false;
}
