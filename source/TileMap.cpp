#include "TileMap.h"
#include <iostream>
#include <utility>

TileMap::TileMap(const char *pathText, const Image &image):
image(image),map(pathText),tiles(){
	
    //Deberia tirar excepcion
    if( map.fail() )
        printf( "Unable to load map file!\n" );

    //Excepcion aca tambien???
    loadMedia();
}

TileMap::~TileMap(){
    map.close();
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
    for( int i = 0; i < TOTAL_TILES; ++i ){
        int tileType(-1);

        map >> tileType;

        if( ( tileType >= 0 ) && ( tileType < TOTAL_TILE_SPRITES ) )
            tiles.push_back(new Tile(tileType,image));
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
    int xOffset(0);
    int yOffset(0);

    for (auto& tile: tiles){
        int type(tile->getType());
        tile->setMBox(tileClips[type-1]);
        
        if (xOffset >= dst.getWidth() ){
            xOffset = 0;
            yOffset += TILE_HEIGHT;
        }

        if ( (xOffset + x) <= ((dst.getWidth()) + TILE_WIDTH) &&
             (yOffset + y) <= ((dst.getHeight()) + TILE_HEIGHT) ){
            Area finalArea(xOffset + x,yOffset + y, 
                       tileClips[type-1].w, tileClips[type-1].h);
            tile->render(finalArea);
        }     
        xOffset += TILE_WIDTH;
    }
}
