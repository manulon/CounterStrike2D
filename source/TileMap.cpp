#include "TileMap.h"
#include <iostream>

TileMap::TileMap(const char *pathText, const Image &image):
image(image),map(pathText),tiles(){
	
    //Deberia tirar excepcion
    if( map.fail() )
        printf( "Unable to load map file!\n" );
}

TileMap::~TileMap(){}

bool TileMap::loadMedia(){
    //Loading success flag
    bool success = true;

    //Load tile map
    if (!setTiles()){
        printf( "Failed to load tile set!\n" );
        success = false;
    }

    return success;
}

bool TileMap::setTiles(){
    bool tilesLoaded = true;
    
    //The tile offsets
    int x = 0, y = 0;

    for( int i = 0; i < TOTAL_TILES; ++i ){
        //Determines what kind of tile will be made
        int tileType = -1;

        //Read tile from map file
        map >> tileType;

        //If the was a problem in reading the map
        //If the number is a valid tile number
        if( ( tileType >= 0 ) && ( tileType < TOTAL_TILE_SPRITES ) ){
            tiles.push_back(new Tile(tileType,image ));
        }else{
            //Stop loading map
            printf( "Stop loading map. End of file. %d!\n", i );
            tilesLoaded = false;
            break;
        }
       	//Move to next tile spot
        x += TILE_WIDTH;

        //If we've gone too far
        if( x >= LEVEL_WIDTH ){
            //Move back
            x = 0;

            //Move to the next row
            y += TILE_HEIGHT;
        }
    }
    
    //Clip the sprite sheet
    if( tilesLoaded ){
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
    }
    //Close the file
    map.close();

    //If the map was loaded fine
    return tilesLoaded;
}

void TileMap::render(const Area &dst){
    std::cout<< "Entro a renderizar" << std::endl;
    std::cout<< "-------------" << std::endl;

    int xOffset(0);
    int yOffset(0);

    for (auto& tile: tiles){
        int type(tile->getType());
        tile->setMBox(tileClips[type-1]);
        
        if (xOffset >= dst.getWidth() ){
            xOffset = 0;
            yOffset += TILE_HEIGHT;
        }

        Area finalArea(xOffset,yOffset, 
                       tileClips[type-1].w, tileClips[type-1].h);

        std::cout<< "Renderizare la imagen numero type" << type << std::endl;
        tile->render(finalArea);
        std::cout<< "-------------" << std::endl;

        xOffset += TILE_WIDTH;
    }
}