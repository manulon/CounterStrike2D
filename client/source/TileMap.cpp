#include "TileMap.h"
#include <iostream>
#include <utility>
#include "yaml-cpp/yaml.h"
#include "RenderizableFactory.h"
#include "Stencil.h"
#include "Pointer.h"
#include "Bullett.h"

TileMap::TileMap(Window & window,const char *pathText, const std::string &pathTiles, const std::string &pathObs) :
window(window),image(pathTiles.c_str(),window),mapName(pathText),
imgObstacles(pathObs.c_str(),window),tiles(), obstacles(), xOffset(0), yOffset(0), 
principalSoldier("../assets/gfx/player/ct4Ak47.png", window),principalSoldierId(-1),
pointer("../assets/gfx/pointer.bmp", window, {0xFF, 0, 0xFF}){
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

void TileMap::setOffset(std::string &size){
    if (size == "huge"){// yaml
        xOffset = 8;
        yOffset = -2;
    } else if (size == "small"){
        xOffset = 0;
        yOffset = -4;
    }  else if (size == "big"){
        xOffset = 4;
        yOffset = -4;
    }
    
}

int TileMap::getxOffset(){
    return xOffset;
}

int TileMap::getyOffset(){
    return yOffset;
}

bool TileMap::setTiles(){
    YAML::Node map = YAML::LoadFile(mapName);
    YAML::Node fields = map["fields"];
    for (unsigned int i = 0; i < fields.size(); i++){
        tiles.push_back(new Tile(fields[i][2].as<int>(), fields[i][0].as<int>()*32,
                                 fields[i][1].as<int>()*32,image));
    }
    std::string size = map["size"].as<std::string>();
    setOffset(size);
    // std::string style = map["style"].as<std::string>(); 
    
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

void TileMap::renderTiles(int x, int y, const Area &dst){
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
    principalSoldier.render();

    // for (auto& object : objects){
    //     object.second->render(x,y);
    // }
    for (auto& soldier: soldiers){
        soldier.second->render(x,y);
    }
    for (auto &object : objects){
        object->render(x,y);
    }
    objects.clear();
}

// void TileMap::updateAndRenderObjects(int x , int y,std::list<Entity*> &serverObjects){
//     RenderizableFactory fac(window);
//     for (auto &object : serverObjects){
//         short id = object->getId();
//         if(fac.createRenderizable(id, objects))
//             objects[id]->setPos((object->getPositionX()+xOffset)*PPM,(object->getPositionY()+yOffset)*PPM);
//     }
//     renderObjects(x,y);
//     objects.clear();
// }

void TileMap::setPrincipalPlayerId(short id){
    principalSoldierId = id;

    if (id% 2 != 0){
        principalSoldier.setAsTerrorist();
    }
}

void TileMap::updateSoldierInfo(short id, float x, float y, short weaponId, short angle){
    if (id == principalSoldierId){
        principalSoldier.updateInfo(x,y, weaponId);
    } else {
        soldiers[id]->updateInfoo((x + (float)xOffset)*PPM, (y + (float)yOffset)*PPM,weaponId,angle);
    } 
}
void TileMap::renderAll(){
    window.clear();
    Area cameraArea(0, 0, 800, 600);
    renderTiles(-(principalSoldier.getX() + xOffset)*PPM,-(principalSoldier.getY() + yOffset)*PPM,cameraArea);
    renderObjects(-(principalSoldier.getX() + xOffset)*PPM,-(principalSoldier.getY() + yOffset)*PPM);
    Area stencilArea((800/2)-(1000/2), (600/2)-(1000/2), 1000, 1000);
    Stencil stencil(1000, 1000, 25, 90, 150, window);
    stencil.render(stencilArea,principalSoldierAngle);
    pointer.render();
    window.render();
}

void TileMap::addNewSoldier(short id){
    if (id % 2 == 0){
        std::unique_ptr<Soldier> soldier(new Soldier("../assets/gfx/player/ct4Ak47.png", window, id));
        soldiers[id] = std::move(soldier);
    } else { 
        std::unique_ptr<Soldier> soldier(new Soldier("../assets/gfx/player/t4Ak47.png", window, id));
        soldiers[id] = std::move(soldier);
    }
}

void TileMap::setSoldierDirection(short angle){
    principalSoldierAngle = angle;
    principalSoldier.setAngle(angle);
}

void TileMap::setPointerPosition(int x, int y){
    pointer.set(x,y);
}

void TileMap::setPrincipalPlayerLife(short life){
    principalSoldier.setLife(life);
}

void TileMap::addNewBullet(float x, float y){
    // bulletsToRender.push_back(std::make_pair((x + (float)xOffset)*PPM, (y + (float)yOffset)*PPM));
    std::unique_ptr<Bullett> bul(new Bullett("../assets/gfx/bullet.png",window));
    bul->setPos((x + (float)xOffset)*PPM, (y + (float)yOffset)*PPM);
    objects.push_back(std::move(bul));
}

void TileMap::updateWeaponInfo(short weaponId, float x, float y){
    std::unique_ptr<Weapon> wea(new Weapon("../assets/gfx/weapons/ak47_d.bmp",window,16,32));
    wea->setPos((x + (float)xOffset)*PPM,(y + (float)yOffset)*PPM);
    objects.push_back(std::move(wea));
}

void TileMap::removePlayer(short id){
    if (id == principalSoldierId){ 
        
    } else {
        soldiers.erase(id);
    }
}
