#include "SizeOptionBig.h"

SizeOptionBig:: SizeOptionBig
(const char *fontPath, int ptsize,
const char *textToRender,Window &window):
MenuOption(fontPath,ptsize,textToRender,window),
window(window){}

SizeOptionBig::~SizeOptionBig(){}

bool SizeOptionBig::clicked(std::vector<MenuOption*>& options){
    return true;
}

void SizeOptionBig::render(){
    Area selectArea(150, 50, 100, 40);              
    optionText.render(selectArea);
}

const char* SizeOptionBig:: getPathToImage(){
    return "";
}

const char* SizeOptionBig:: getMapName(){
    return "";
}

void SizeOptionBig::setPair(std::pair<int,int>& pair){
    pair.first = 1056;
    pair.second = 472;
}