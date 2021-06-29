#include "SdlColor.h"

SdlColor::SdlColor(int r, int g, int b){
    textColor = {0,0,0};
}

SDL_Color& SdlColor::getColor(){
    return textColor;
}

SdlColor::~SdlColor(){}