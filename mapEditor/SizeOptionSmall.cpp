#include "SizeOptionSmall.h"

SizeOptionSmall:: SizeOptionSmall
(const char *fontPath, int ptsize,
const char *textToRender,Window &window):
MenuOption(fontPath,ptsize,textToRender,window),
window(window){}

SizeOptionSmall::~SizeOptionSmall(){}

bool SizeOptionSmall::clicked(std::vector<MenuOption*>& options){
    return true;
}

void SizeOptionSmall::render(){
    Area selectArea(0, 50, 75, 40);              
    optionText.render(selectArea);
}

const char* SizeOptionSmall:: getPathToImage(){
    return "";
}

const char* SizeOptionSmall:: getMapName(){
    return "";
}

void SizeOptionSmall::setPair(std::pair<int,int>& pair){
    pair.first = 500;
    pair.second = 500;
}