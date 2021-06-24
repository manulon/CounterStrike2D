#ifndef TILE_H
#define TILE_H

#include "Window.h"
#include "Image.h"
#include "SdlTexture.h"
#include "SdlRenderer.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <fstream>


class Tile{
public:
	//Initializes position and type
    Tile(int tileType, const Image &image);
    ~Tile();

    //Shows the tile
    void render(const Area &dest);

    //Get the tile type
    int getType();

    void setMBox(const SDL_Rect &mBox);

    SDL_Rect mBox;
private:
    //The attributes of the tile
    

    //The tile type
    int mType;

    const Image &image;
};

#endif