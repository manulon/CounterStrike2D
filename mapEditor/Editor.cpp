#include "Editor.h"
#include <iostream>
#include <unistd.h>
#include <utility>

Editor::Editor(const char* path,const char* mapName,
               std::pair<int,int>& size): 
window("Counter Strike 2D", size.first, size.second, 
        SDL_WINDOW_RESIZABLE,SDL_INIT_VIDEO | SDL_INIT_AUDIO),
image(path,window),selectedTile("../assets/gfx/selectedTile.png",window),
obsImage("../assets/gfx/tiles/obstacles.png",window),finalMapTiles()               ,
eventHandler(window,image,obsImage,mapName,finalMapTiles),editor(mapName),sizeName(""),
tileBoxHeight(0),tileWidth(0),tileHeight(0){
    YAML::Node readerNode = YAML::LoadFile("../assets/config/editor_config.yaml");
    tileBoxHeight = readerNode["config"]["tile_box_height"].as<int>();
    tileWidth     = readerNode["config"]["tile_width"].as<int>();
    tileHeight    = readerNode["config"]["tile_height"].as<int>();
}                                     

void Editor::showGrid(){
    Area gridSourceArea(32,0,32,32);
    Area gridArea(0, 0, 32, 32);
    Area selectedArea(window.getWidth()/2,window.getHeight()-90,40,40);

    while ( gridArea.getY() < (window.getHeight() - tileBoxHeight) ){
        finalMapTiles[std::make_pair(gridArea.getX()/PPM,
                                     gridArea.getY()/PPM)] = 2;
        image.render(gridSourceArea,gridArea);
    
        gridArea.setX( gridArea.getX() + tileWidth); 

        if ( gridArea.getX()>(window.getWidth() - tileWidth )){
            gridArea.setX(0);
            gridArea.setY( gridArea.getY() + tileHeight);
        }
    }
    selectedTile.render(selectedArea);
    for (auto& button: tileOptionButton){
        button->render();
    }
}

bool Editor::handleEvents(){
    setSizeName();
    return eventHandler.handleEvents(tiles,optionTiles,obstaclesOptionTiles,
                                     tileOptionButton,soldierOptionTiles,sizeName);
}

void Editor::fillTileOptionList(){
    tileOptionButton.push_back(new ButtonBox(window,editor));
    tileOptionButton.push_back(new ButtonFloor(window,editor));
    tileOptionButton.push_back(new ButtonMisc(window,editor));
    tileOptionButton.push_back(new ButtonObstacles(window,editor));
    tileOptionButton.push_back(new ButtonWeaponCharacter(window,editor));
}

void Editor::setSizeName(){
    if (window.getWidth() == SMALL_WIDTH){
        sizeName = "small";
    }else if (window.getWidth() == BIG_WIDTH){
        sizeName = "big";
    }else if (window.getWidth() == HUGE_WIDTH){
        sizeName = "huge";
    }
}

void Editor::clearWindow(){
    window.clear();
}

void Editor::render(){
    window.render();
}

Editor::~Editor(){
    for(auto& tile : optionTiles){
        delete tile;
    }

    for(auto& tile : tiles){
        delete tile;
    }

    for(auto& button : tileOptionButton){
        delete button;
    }
}