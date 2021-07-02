#include "MenuOptionSelectMode.h"
#include <iostream>

MenuOptionSelectMode:: MenuOptionSelectMode
(const char *fontPath, int ptsize,
const char *textToRender,Window &window):
MenuOption(fontPath,ptsize,textToRender,window),
window(window){}

MenuOptionSelectMode::~MenuOptionSelectMode(){}

bool MenuOptionSelectMode::clicked(std::vector<MenuOption*>& options){
    options.push_back(new MapOptionAztec(window));
    options.push_back(new MapOptionDust(window));
    options.push_back(new MapOptionInferno(window));
    return true;
}



void MenuOptionSelectMode::render(){
    Area selectArea(0, 50, 150, 40);              
    optionText.render(selectArea);
}

const char* MenuOptionSelectMode:: getPathToImage(){
    return "nothing";
}

const char* MenuOptionSelectMode:: getMapName(){
    return "";
}

void MenuOptionSelectMode::setPair(std::pair<int,int>& pair){}
