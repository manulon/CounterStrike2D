#include "MapOptionAztec.h"
#include <iostream>
#include <unistd.h>


MapOptionAztec:: MapOptionAztec(Window& window): 
MenuOption("assets/gfx/buttons/ButtonAztec.png",window,250,60,239,32),
window(window){}

MapOptionAztec::~MapOptionAztec(){}

const char* MapOptionAztec:: getPathToImage(){
    return "assets/gfx/tiles/default_aztec.png";            // Tiene que estar en YAML config
}

const char* MapOptionAztec::getMapName(){
    return "aztec";
}

void MapOptionAztec::render(){
    button.render(buttonArea);
}

bool MapOptionAztec::clicked(std::vector<MenuOption*>& options){
    return false;
}

void MapOptionAztec::setPair(std::pair<int,int>& pair){}

bool MapOptionAztec::mouseInButton(int x, int y){
    if ( (x > buttonArea.getX() && x < (buttonArea.getX() + buttonArea.getWidth()) &&
         (y > buttonArea.getY() && y < (buttonArea.getY() + buttonArea.getHeight())) )) {
         return true;
    }
    return false;
}