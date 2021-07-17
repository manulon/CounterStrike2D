#include "GameOption.h"

GameOption::GameOption(const char *path,Window &window,
                       int x, int y, int w, int h):
button(path,window),buttonArea(x,y,w,h){}

bool GameOption::mouseInButton(int x, int y){
    if ( (x > buttonArea.getX() && x < (buttonArea.getX() + buttonArea.getWidth()) &&
         (y > buttonArea.getY() && y < (buttonArea.getY() + buttonArea.getHeight())) )) {
         return true;
    }
    return false;
}

void GameOption::render(){
    button.render(buttonArea);
}

GameOption::~GameOption(){}