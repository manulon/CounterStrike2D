#include "MenuOption.h"
#include <iostream>

MenuOption::MenuOption(const char *fontPath, int ptsize,
		               const char *textToRender, 
		               SDL_Color color, Window &window): 
optionText(fontPath,ptsize,textToRender,color,window){}

//MenuOption::MenuOption();

void MenuOption::render(const Area &dest){
    optionText.render(dest);
}

bool MenuOption::mouseInText(int x, int y){
    return optionText.mouseInText(x,y);
}

MenuOption::~MenuOption(){}