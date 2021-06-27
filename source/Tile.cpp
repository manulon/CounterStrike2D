#include "Tile.h"
#include <utility>

Tile::Tile(int tileType,int x, int y, const Image &image ):
type(tileType),posX(x),posY(y), image(image){}

Tile::Tile(Tile &&other) : 
    mBox(other.mBox),type(other.type),
    image(std::move(other.image)){
    other.type = 0;
}

Tile::~Tile(){}

int Tile::getType(){
    return type;
}

int Tile::getX(){
    return posX;
}
int Tile::getY(){
    return posY;
}

/*
oid Image::render(int x, int y, const Area &dest) const {
    SDL_Rect srcrect = {0, 0, 
                        sdlTexture.getWidth(), sdlTexture.getHeight()};
    SDL_Rect destrect = {x, y, 
                         dest.getWidth(), dest.getHeight()};

    sdlRenderer.renderCopyEx( sdlTexture.getTexture(), &srcrect, &destrect, 0, SDL_FLIP_NONE);
}
*/

void Tile::render(const Area& dest){
    Area src(mBox.x, mBox.y, mBox.w, mBox.h);
    image.render(src,dest);
}

void Tile::setMBox(const SDL_Rect &mBox){
    this->mBox = mBox;
}