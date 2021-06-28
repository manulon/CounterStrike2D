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
    Tile(int tileType, int x, int y,const Image &image);
    Tile(Tile &&other);
    ~Tile();

    void render(const Area &dest);
    int getType();
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void setMBox(const SDL_Rect &mBox);
    bool mouseInTile(int x , int y);
    
private:
    SDL_Rect mBox;
    int type;
    int posX;
    int posY;
    int centerX;
    int centerY;
    const Image &image;
    bool selected;

    Tile(const Tile &other) = delete;
    Tile& operator=(const Tile &other) = delete;
    Tile& operator=(Tile &&other) = delete;
};

#endif