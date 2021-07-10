#include "SizeOptionBig.h"

SizeOptionBig:: SizeOptionBig(Window &window):
MenuOption("../assets/gfx/buttons/ButtonBig.png",window,240,50,237,32),
window(window){}

SizeOptionBig::~SizeOptionBig(){}

bool SizeOptionBig::clicked(std::vector<MenuOption*>& options){
    return true;
}

void SizeOptionBig::render(){
    button.render(buttonArea);
}

const char* SizeOptionBig:: getPathToImage(){
    return "";
}

const char* SizeOptionBig:: getMapName(){
    return "";
}

void SizeOptionBig::setPair(std::pair<int,int>& pair){
    pair.first = 1056;
    pair.second = 472;
}

bool SizeOptionBig::mouseInButton(int x, int y){
    if ( (x > buttonArea.getX() && x < (buttonArea.getX() + buttonArea.getWidth()) &&
         (y > buttonArea.getY() && y < (buttonArea.getY() + buttonArea.getHeight())) )) {
         return true;
    }
    return false;
}