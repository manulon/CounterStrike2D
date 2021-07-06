#ifndef TILEMAP_H
#define TILEMAP_H
#include <map>
#include "Tile.h"
#include "Image.h"
#include "Window.h"
#include "Area.h"
#include <list>
#include "Soldier.h"
#include "DynamicObject.h"
#include "Entity.h"// esto tiene que volar
// #include "yaml-cpp/yaml"

/* Esto no deberia estar en un archivo aparte? Preguntar al profe */
#define LEVEL_WIDTH  		800
#define LEVEL_HEIGHT  		600
#define TILE_WIDTH  		32
#define TILE_HEIGHT  		32
#define TOTAL_TILES  		625
#define TOTAL_TILE_SPRITES  75
#define ROW_WIDTH  			160

class TileMap{
private:
	Window &window;
	const Image &image;
	std::string mapName;
	SDL_Rect tileClips[ TOTAL_TILE_SPRITES ];
	const Image &imgObstacles;
	SDL_Rect obsClips[80];
	std::list<Tile*> tiles;
	std::list<Tile*> obstacles;
	std::map<short,std::unique_ptr<DynamicObject>> objects;
	// std::list<std::unique_ptr<DynamicObject>> renderizables;

	TileMap(const TileMap &other) = delete;
    TileMap& operator=(const TileMap &other) = delete;
    TileMap& operator=(TileMap &&other) = delete;
public:
	TileMap(Window &window, const char *pathText, const Image &image, const Image &obs);
	~TileMap();
	void addDynamicObject(short id, DynamicObject *object);
	bool loadMedia();
	bool setTiles();
	void render(int x, int y, const Area &dest);
	void renderObjects(int x,int y);
	void updateAndRenderObjects(int x , int y,std::list<Entity*> &serverObjects);// este metodo emula el mensaje que llega del server
	
};

#endif