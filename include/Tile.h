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
    void render();

    //Get the tile type
    int getType();

    void setMBox(SDL_Rect &mBox);

private:
    //The attributes of the tile
    SDL_Rect mBox;

    //The tile type
    int mType;

    const Image &image;
};

#endif