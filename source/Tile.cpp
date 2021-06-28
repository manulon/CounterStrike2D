#include "Tile.h"
#include <utility>
#include <iostream>

Tile::Tile(int tileType,int x, int y, const Image &image ):
type(tileType),posX(x),posY(y),centerX(x+16),centerY(y+16), //El 16 tiene q estar en yaml
image(image),selected(false){                               //o a lo sumo es 32(Width)/2.
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

void Tile::render(){
    Area src(mBox.x, mBox.y, mBox.w, mBox.h);
    Area dest(posX, posY, mBox.w, mBox.h);

    image.render(src,dest);
}

void Tile::setMBox(const SDL_Rect &mBox){
    this->mBox = mBox;
}

void Tile::setMBox(const Area &area){
    this->mBox = {area.getX(), area.getY(), 
                  area.getWidth(), area.getHeight()};
}

bool Tile::mouseInTile(int x, int y){    // El 16 tiene que ser del YAML   
    if ((x < (centerX - 16) && y < (centerY - 16) )  ||
        (x > (centerX + 16) && y < (centerY - 16) )  ||
        (x < (centerX - 16) && y > (centerY + 16) )  ||
        (x > (centerX + 16) && y > (centerY + 16) )){
        return false;
    }
    return true;
}
