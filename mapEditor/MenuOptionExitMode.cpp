#include "MenuOptionExitMode.h"
#include <iostream>

MenuOptionExitMode:: MenuOptionExitMode
(const char *fontPath, int ptsize,
const char *textToRender,Window &window):
MenuOption(fontPath,ptsize,textToRender,window){}

MenuOptionExitMode::~MenuOptionExitMode(){}

bool MenuOptionExitMode::clicked(std::vector<MenuOption*>& options){
    std::cout <<"Aprete la opcion salir"<< std::endl;
    return false;
}

void MenuOptionExitMode::render(){
    Area exitArea(0, 100, 100, 30);              
    optionText.render(exitArea);
}

const char* MenuOptionExitMode:: getPathToImage(){
    return nullptr;
}