#include "TileMap.h"
#include <iostream>
#include <utility>
#include "yaml-cpp/yaml.h"
#include "RenderizableFactory.h"

TileMap::TileMap(Window & window,const char *pathText, const std::string &pathTiles, const std::string &pathObs) :
window(window),image(pathTiles.c_str(),window),mapName(pathText),
imgObstacles(pathObs.c_str(),window),tiles(), obstacles(){
	
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
    for (auto& obstacle : obstacles){
        delete obstacle;
    }
    // for (auto& object : objects){
    //     delete object.second;
    // }
}

bool TileMap::loadMedia(){
    if (!setTiles()){
        printf( "Failed to load tile set!\n" );
        return false;
    }
    return true;
}

void TileMap::addDynamicObject(short id, DynamicObject *object){
    // objects[id] = (object);
}

bool TileMap::setTiles(){
    YAML::Node map = YAML::LoadFile(mapName);
    YAML::Node fields = map["fields"];
    for (unsigned int i = 0; i < fields.size(); i++){
        tiles.push_back(new Tile(fields[i][2].as<int>(), fields[i][0].as<int>()*32,
                                 fields[i][1].as<int>()*32,image));
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
    YAML::Node obsyaml = map["obstacles"];
    for (unsigned int i=0; i< obsyaml.size(); i++){
        obstacles.push_back(new Tile(obsyaml[i][2].as<int>(),
         obsyaml[i][0].as<int>()*32, obsyaml[i][1].as<int>()*32,imgObstacles));
    }
    x_aux = 0;
    y_aux = 0;
    for (int i=0; i<80; i++){
        obsClips[i].x = x_aux;
        obsClips[i].y = y_aux;
        obsClips[i].w = TILE_WIDTH;
        obsClips[i].h = TILE_HEIGHT;

        x_aux += TILE_WIDTH;

        if (x_aux==160){
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
    for (auto& tile: obstacles){
        int xOffset(tile->getX());
        int yOffset(tile->getY());
        int type(tile->getType());
        tile->setMBox(obsClips[type-1]);

        if ( (xOffset + x) <= ((dst.getWidth()) + TILE_WIDTH) &&
             (yOffset + y) <= ((dst.getHeight()) + TILE_HEIGHT) ){
            Area finalArea(xOffset + x,yOffset + y, 
                       obsClips[type-1].w, obsClips[type-1].h);
            tile->render(finalArea);
        }
    }
}

void TileMap::renderObjects(int x,int y){
    for (auto& object : objects){
        object.second->render(x,y);
    }
}

void TileMap::updateAndRenderObjects(int x , int y,std::list<Entity*> &serverObjects){
    RenderizableFactory fac(window);
    for (auto &object : serverObjects){
        short id = object->getId();
        if(fac.createRenderizable(id, objects))
            objects[id]->setPos((object->getPositionX()+8)*32,(object->getPositionY()-2)*32);
    }
    renderObjects(x,y);
    objects.clear();
}