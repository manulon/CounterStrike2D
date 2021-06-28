#include "Tile.h"
#include <utility>
#include <iostream>

Tile::Tile(int tileType,int x, int y, const Image &image ):
type(tileType),posX(x),posY(y),image(image),selected(false){                               
}                             

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

void Tile::setX(int x){
    posX = x;
}
void Tile::setY(int y){
    posY = y;
}

void Tile::render(const Area& dest){
    Area src(mBox.x, mBox.y, mBox.w, mBox.h);
    image.render(src,dest);
}

void Tile::setMBox(const SDL_Rect &mBox){
    this->mBox = mBox;
}

bool Tile::mouseInTile(int x, int y){// El 32 tiene que ser del YAML  
    if ( ((x>posX) && (x<(posX + 32))) && 
         ((y>posY) && (y<(posY + 32))) ){
        return true;
    }
    return false;
}

bool Tile::tileOutOfPosition(){
    if ((posX % 32) == 0)
        return false;

    if ((posY % 32) == 0)
        return false;

    return true;
}