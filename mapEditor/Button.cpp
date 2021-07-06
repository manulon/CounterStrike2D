#include "Button.h"
#include <iostream>

Button::Button(const char *path,Window &window,EditorConfig& editor,
               int x, int y, int w, int h):
button(path,window),buttonArea(x,y,w,h),editor(editor){}

bool Button::mouseInText(int x, int y){
    if ( (x > buttonArea.getX() && x < (buttonArea.getX() + buttonArea.getWidth()) &&
         (y > buttonArea.getY() && y < (buttonArea.getY() + buttonArea.getHeight())) )) {
         return true;
    }
    return false;
}

Button::~Button(){}