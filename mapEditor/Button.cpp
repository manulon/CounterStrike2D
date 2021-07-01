#include "Button.h"
#include <iostream>

Button::Button(const char *fontPath, int ptsize,
		               const char *textToRender, 
		               Window &window):
color(0,0,0),
textBox(fontPath,ptsize,textToRender,color.getColor(),window){}

bool Button::mouseInText(int x, int y){
    return textBox.mouseInText(x,y);
}

Button::~Button(){}