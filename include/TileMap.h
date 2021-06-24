#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"
#include "Image.h"
#include "Window.h"
#include "Area.h"
#include <list>

//The dimensions of the level
/* ESTO NO DEBERIA SER UNA CONSTANTE!!!!!! */
const int LEVEL_WIDTH = 800;
const int LEVEL_HEIGHT = 600;
const int TILE_WIDTH = 32;
const int TILE_HEIGHT = 32;
const int TOTAL_TILES = 625;
const int TOTAL_TILE_SPRITES = 75;
const int ROW_WIDTH = 160;

class TileMap{
private:
	const Image &image;
	/*ESTO VA A DESAPARECER EN REFACTOR*/ const char* path_auxiliar;
	std::ifstream map;
	//Podria ser una area
	SDL_Rect tileClips[ TOTAL_TILE_SPRITES ];
	std::list<Tile*> tiles;

public:
	TileMap(const char *pathText, const Image &image);
	~TileMap();

	//Loads media
	bool loadMedia();

	//Frees media and shuts down SDL
	/*No esta implementado!!!!!!! osea que estoy perdiendo memoria*/
	void close();

	//Sets tiles from tile map
	bool setTiles();

	void render(const Area &dest);
};

#endif