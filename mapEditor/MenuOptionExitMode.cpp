#include "MenuOptionExitMode.h"
#include <iostream>

MenuOptionExitMode:: MenuOptionExitMode
(const char *fontPath, int ptsize,
const char *textToRender, 
SDL_Color color, Window &window):
MenuOption(fontPath,ptsize,textToRender,color,window){}

MenuOptionExitMode::~MenuOptionExitMode(){}

bool MenuOptionExitMode::clicked(){
    std::cout <<"Aprete la opcion salir"<< std::endl;
    return false;
}