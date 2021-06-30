#include "MenuOptionSelectMode.h"
#include <iostream>

MenuOptionSelectMode:: MenuOptionSelectMode
(const char *fontPath, int ptsize,
const char *textToRender, 
SDL_Color color, Window &window):
MenuOption(fontPath,ptsize,textToRender,color,window){}

MenuOptionSelectMode::~MenuOptionSelectMode(){}

bool MenuOptionSelectMode::clicked(){
    std::cout <<"Aprete la opcion seleccionar modo"<< std::endl;
    return true;
}