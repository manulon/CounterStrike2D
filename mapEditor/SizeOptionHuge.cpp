#include "SizeOptionHuge.h"

SizeOptionHuge:: SizeOptionHuge(Window &window):
MenuOption("../assets/gfx/buttons/ButtonHuge.png",window,480,50,237,32),
window(window){}

SizeOptionHuge::~SizeOptionHuge(){}

bool SizeOptionHuge::clicked(std::vector<MenuOption*>& options){
    return true;
}

void SizeOptionHuge::render(){
    button.render(buttonArea);
}

const char* SizeOptionHuge:: getPathToImage(){
    return "";
}

const char* SizeOptionHuge:: getMapName(){
    return "";
}

void SizeOptionHuge::setPair(std::pair<int,int>& pair){
    pair.first = 1312;
    pair.second = 600;
}

bool SizeOptionHuge::mouseInButton(int x, int y){
    if ( (x > buttonArea.getX() && x < (buttonArea.getX() + buttonArea.getWidth()) &&
         (y > buttonArea.getY() && y < (buttonArea.getY() + buttonArea.getHeight())) )) {
         return true;
    }
    return false;
}