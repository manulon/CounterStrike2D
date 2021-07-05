#include "Editor.h"
#include <iostream>
#include <unistd.h>
#include <utility>

Editor::Editor(Window& window,const char* path,const char* mapName,
               std::pair<int,int>& size): 
window(window),grid("assets/gfx/emptySpace.png", window),
image(path,window),selectedTile("assets/gfx/selectedTile.png",window),
obsImage("assets/gfx/tiles/obstacles.png",window),               
eventHandler(window,image,obsImage,mapName),editor(mapName),size(size),sizeName(""){}                                     

void Editor:: showGrid(){    
    Area gridArea(0, 0, 32, 32);
    Area selectedArea(window.getWidth()/2,window.getHeight()-90,40,40);
    while ( gridArea.getY() < (window.getHeight() - 128) ){ /* CONSTANTE EL 128 */
        grid.render(gridArea);
    
        gridArea.setX( gridArea.getX() + 32); /*ACA VA LO DEL YAML CREO (tile width).*/

        if ( gridArea.getX()>(window.getWidth() - 32 )){
            gridArea.setX(0);
            gridArea.setY( gridArea.getY() + 32); /*ACA VA LO DEL YAML CREO (tile height).*/ 
        }
    }
    selectedTile.render(selectedArea);
    for (auto& button: tileOptionButton){
        button->render();
    }
}

bool Editor:: handleEvents(){
    setSizeName();
    return eventHandler.handleEvents(tiles,optionTiles,obstaclesOptionTiles,
                                     tileOptionButton,sizeName);
}

void Editor::fillTileOptionList(){
    tileOptionButton.push_back(new ButtonBox(window,editor));
    tileOptionButton.push_back(new ButtonFloor(window,editor));
    tileOptionButton.push_back(new ButtonMisc(window,editor));
    tileOptionButton.push_back(new ButtonObstacles(window,editor));
    tileOptionButton.push_back(new ButtonWall(window,editor));
    tileOptionButton.push_back(new ButtonWeaponCharacter(window,editor));
}

void Editor::setSizeName(){
    if (size.first == SMALL_WIDTH){
        sizeName = "small";
    }else if (size.first == BIG_WIDTH){
        sizeName = "big";
    }else if (size.first == HUGE_WIDTH){
        sizeName = "huge";
    }
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