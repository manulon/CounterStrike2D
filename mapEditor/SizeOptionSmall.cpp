#include "SizeOptionSmall.h"

SizeOptionSmall:: SizeOptionSmall(Window &window):
MenuOption("../assets/gfx/buttons/ButtonSmall.png",window,0,50,237,32),
window(window){}

SizeOptionSmall::~SizeOptionSmall(){}

bool SizeOptionSmall::clicked(std::vector<MenuOption*>& options){
    return true;
}

void SizeOptionSmall::render(){
    button.render(buttonArea);
}

const char* SizeOptionSmall:: getPathToImage(){
    return "";
}

const char* SizeOptionSmall:: getMapName(){
    return "";
}

void SizeOptionSmall::setPair(std::pair<int,int>& pair){
    pair.first = 800;
    pair.second = 472;
}

bool SizeOptionSmall::mouseInButton(int x, int y){
    if ( (x > buttonArea.getX() && x < (buttonArea.getX() + buttonArea.getWidth()) &&
         (y > buttonArea.getY() && y < (buttonArea.getY() + buttonArea.getHeight())) )) {
         return true;
    }
    return false;
}