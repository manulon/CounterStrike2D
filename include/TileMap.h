#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"
#include "Image.h"
#include "Window.h"
#include "Area.h"
#include <list>

/* ESTO NO DEBERIA SER UNA CONSTANTE!!!!!! Preguntar al profe */
#define LEVEL_WIDTH  		800
#define LEVEL_HEIGHT  		600
#define TILE_WIDTH  		32
#define TILE_HEIGHT  		32
#define TOTAL_TILES  		625
#define TOTAL_TILE_SPRITES  75
#define ROW_WIDTH  			160

class TileMap{
private:
	const Image &image;
	std::ifstream map;
	SDL_Rect tileClips[ TOTAL_TILE_SPRITES ];
	std::list<Tile*> tiles;

	TileMap(const TileMap &other) = delete;
    TileMap& operator=(const TileMap &other) = delete;
    TileMap& operator=(TileMap &&other) = delete;

public:
	TileMap(const char *pathText, const Image &image);
	~TileMap();

	bool loadMedia();
	bool setTiles();
	void render(const Area &dest);
};

#endif