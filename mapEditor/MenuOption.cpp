#include "MenuOption.h"
#include <iostream>

MenuOption::MenuOption(const char *fontPath, int ptsize,
		               const char *textToRender, 
		               Window &window):
color(0,0,0),
optionText(fontPath,ptsize,textToRender,color.getColor(),window){}

bool MenuOption::mouseInText(int x, int y){
    return optionText.mouseInText(x,y);
}

MenuOption::~MenuOption(){}