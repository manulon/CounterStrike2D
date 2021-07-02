#include "MenuOptionExitMode.h"
#include <iostream>

MenuOptionExitMode:: MenuOptionExitMode
(const char *fontPath, int ptsize,
const char *textToRender,Window &window):
MenuOption(fontPath,ptsize,textToRender,window){}

MenuOptionExitMode::~MenuOptionExitMode(){}

bool MenuOptionExitMode::clicked(std::vector<MenuOption*>& options){
    return false;
}

void MenuOptionExitMode::render(){
    Area exitArea(0, 100, 100, 30);              
    optionText.render(exitArea);
}

const char* MenuOptionExitMode:: getPathToImage(){
    return "no path";
}

const char* MenuOptionExitMode:: getMapName(){
    return "";
}

void MenuOptionExitMode::setPair(std::pair<int,int>& pair){}
