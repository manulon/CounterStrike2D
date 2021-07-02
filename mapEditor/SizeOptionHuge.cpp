#include "SizeOptionHuge.h"

SizeOptionHuge:: SizeOptionHuge
(const char *fontPath, int ptsize,
const char *textToRender,Window &window):
MenuOption(fontPath,ptsize,textToRender,window),
window(window){}

SizeOptionHuge::~SizeOptionHuge(){}

bool SizeOptionHuge::clicked(std::vector<MenuOption*>& options){
    return true;
}

void SizeOptionHuge::render(){
    Area selectArea(275, 50, 125, 40);              
    optionText.render(selectArea);
}

const char* SizeOptionHuge:: getPathToImage(){
    return "";
}

const char* SizeOptionHuge:: getMapName(){
    return "";
}

void SizeOptionHuge::setPair(std::pair<int,int>& pair){
    pair.first = 1600;
    pair.second = 1200;
}