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
    Tile(int tileType, const Image &image);
    Tile(Tile &&other);
    ~Tile();

    void render(const Area &dest);
    int getType();
    void setMBox(const SDL_Rect &mBox);

    
private:
    SDL_Rect mBox;
    int type;
    const Image &image;

    Tile(const Tile &other) = delete;
    Tile& operator=(const Tile &other) = delete;
    Tile& operator=(Tile &&other) = delete;
};

#endif