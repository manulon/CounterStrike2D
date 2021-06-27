#include "TileMap.h"
#include <iostream>
#include <utility>
#include "yaml-cpp/yaml.h"

TileMap::TileMap(const char *pathText, const Image &image):
image(image),mapName(pathText),tiles(){
	
    //Deberia tirar excepcion
    // if( map.fail() )
    //     printf( "Unable to load map file!\n" );

    //Excepcion aca tambien???
    loadMedia();
}

TileMap::~TileMap(){
    // map.close();
    for (auto& tile: tiles){
       delete tile;
    }
}

bool TileMap::loadMedia(){
    if (!setTiles()){
        printf( "Failed to load tile set!\n" );
        return false;
    }
    return true;
}

bool TileMap::setTiles(){
    YAML::Node map = YAML::LoadFile(mapName);
    YAML::Node fields = map["fields"];
    for (unsigned int i = 0; i < fields.size(); i++){
        tiles.push_back(new Tile(fields[i][2].as<int>(), fields[i][0].as<int>(),fields[i][1].as<int>(),image));
    }

    int x_aux(0);
    int y_aux(0);

    for (int i=0; i<TOTAL_TILE_SPRITES; i++){
        tileClips[i].x = x_aux;
        tileClips[i].y = y_aux;
        tileClips[i].w = TILE_WIDTH;
        tileClips[i].h = TILE_HEIGHT;

        x_aux += TILE_WIDTH;

        if (x_aux==ROW_WIDTH){
        	x_aux=0;
        	y_aux+=TILE_HEIGHT;
        }
    }

    return true;
}



void TileMap::render(int x, int y, const Area &dst){

    for (auto& tile: tiles){
        int xOffset(tile->getX());
        int yOffset(tile->getY());
        int type(tile->getType());
        tile->setMBox(tileClips[type-1]);

        if ( (xOffset + x) <= ((dst.getWidth()) + TILE_WIDTH) &&
             (yOffset + y) <= ((dst.getHeight()) + TILE_HEIGHT) ){
            Area finalArea(xOffset + x,yOffset + y, 
                       tileClips[type-1].w, tileClips[type-1].h);
            tile->render(finalArea);
        } 
    }
}
