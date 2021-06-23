#include "Tile.h"

Tile::Tile(int tileType, const Image &image ):
mType(tileType), image(image){}

Tile::~Tile(){}

int Tile::getType(){
    return mType;
}

void Tile::render(){
    Area dest(mBox.x, mBox.y, mBox.w, mBox.h);
    image.render(dest);
}

void Tile::setMBox(SDL_Rect &mBox){
    this->mBox = mBox;
}