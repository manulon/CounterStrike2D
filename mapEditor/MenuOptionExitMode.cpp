#include "MenuOptionExitMode.h"
#include <iostream>

MenuOptionExitMode:: MenuOptionExitMode
(const char *fontPath, int ptsize,
const char *textToRender,Window &window):
MenuOption("assets/gfx/buttons/ButtonSalir.png",window,5,100,237,32){}

MenuOptionExitMode::~MenuOptionExitMode(){}

bool MenuOptionExitMode::clicked(std::vector<MenuOption*>& options){
    return false;
}

void MenuOptionExitMode::render(){
    button.render(buttonArea);
}

const char* MenuOptionExitMode:: getPathToImage(){
    return "no path";
}

const char* MenuOptionExitMode:: getMapName(){
    return "";
}

void MenuOptionExitMode::setPair(std::pair<int,int>& pair){}

bool MenuOptionExitMode::mouseInButton(int x, int y){
    if ( (x > buttonArea.getX() && x < (buttonArea.getX() + buttonArea.getWidth()) &&
         (y > buttonArea.getY() && y < (buttonArea.getY() + buttonArea.getHeight())) )) {
         return true;
    }
    return false;
}