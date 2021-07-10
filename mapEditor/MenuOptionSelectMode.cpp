#include "MenuOptionSelectMode.h"
#include <iostream>

MenuOptionSelectMode:: MenuOptionSelectMode
(const char *fontPath, int ptsize,
const char *textToRender,Window &window):
MenuOption("../assets/gfx/buttons/ButtonMap.png",window,5,50,237,32),
window(window){}

MenuOptionSelectMode::~MenuOptionSelectMode(){}

bool MenuOptionSelectMode::clicked(std::vector<MenuOption*>& options){
    options.push_back(new MapOptionAztec(window));
    options.push_back(new MapOptionDust(window));
    options.push_back(new MapOptionInferno(window));
    return true;
}

void MenuOptionSelectMode::render(){
    button.render(buttonArea);
}

const char* MenuOptionSelectMode:: getPathToImage(){
    return "";
}

const char* MenuOptionSelectMode:: getMapName(){
    return "";
}

void MenuOptionSelectMode::setPair(std::pair<int,int>& pair){}

bool MenuOptionSelectMode::mouseInButton(int x, int y){
    if ( (x > buttonArea.getX() && x < (buttonArea.getX() + buttonArea.getWidth()) &&
         (y > buttonArea.getY() && y < (buttonArea.getY() + buttonArea.getHeight())) )) {
         return true;
    }
    return false;
}
