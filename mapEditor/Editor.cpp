#include "Editor.h"
#include <iostream>
#include <unistd.h>
#include <utility>

Editor::Editor(Window& window,const char* path,const char* mapName): 
window(window),grid("assets/gfx/emptySpace.png", window),
image(path,window),selectedTile("assets/gfx/option2.png",window),               
eventHandler(window,image),editor(mapName){}                                     

void Editor:: showGrid(){    
    Area gridArea(0, 0, 32, 32);
    Area selectedArea(384,497,40,40);
    while ( gridArea.getY() < (window.getHeight() - 128) ){ /* CONSTANTE EL 128 */
        grid.render(gridArea);
    
        gridArea.setX( gridArea.getX() + 32); /*ACA VA LO DEL YAML CREO (tile width).*/

        if ( gridArea.getX()>window.getWidth() ){
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
    return eventHandler.handleEvents(tiles,optionTiles,tileOptionButton);
}

void Editor::fillTileOptionList(){
    tileOptionButton.push_back(new ButtonBox(window,editor));
    tileOptionButton.push_back(new ButtonFloor(window,editor));
    tileOptionButton.push_back(new ButtonMisc(window,editor));
    tileOptionButton.push_back(new ButtonObstacles(window,editor));
    tileOptionButton.push_back(new ButtonWall(window,editor));
    tileOptionButton.push_back(new ButtonWeaponCharacter(window,editor));
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