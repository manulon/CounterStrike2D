#include "Tile.h"

Tile::Tile(int tileType, const Image &image ):
mType(tileType), image(image){}

Tile::~Tile(){}

int Tile::getType(){
    return mType;
}

/*
    void Image::render(const Area &src, const Area &dest) const {
    render(src, dest, DEFAULT_ANGLE, SDL_FLIP_NONE);
}
*/

void Tile::render(const Area& dest){
    Area src(mBox.x, mBox.y, mBox.w, mBox.h);
    printf( " En la posicion = {%d,%d}\n",dest.getX(),dest.getY());
    image.render(src,dest);
}

void Tile::setMBox(const SDL_Rect &mBox){
    this->mBox = mBox;
}