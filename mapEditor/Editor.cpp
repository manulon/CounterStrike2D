#include "Editor.h"
#include <iostream>
#include <unistd.h>
#include <utility>

Editor::Editor(Window& window,const char* path): 
window(window),grid("assets/gfx/emptySpace.png", window),
selectedTile("assets/gfx/option2.png",window),image(path, window),               
eventHandler(window,image){}                                     

void Editor:: showGrid(){    
    Area gridArea(0, 0, 32, 32);
    Area selectedArea(380,497,40,40);
    while ( gridArea.getY() < (window.getHeight() - 128) ){ /* CONSTANTE EL 128 */
        grid.render(gridArea);
    
        gridArea.setX( gridArea.getX() + 32); /*ACA VA LO DEL YAML CREO (tile width).*/

        if ( gridArea.getX()>window.getWidth() ){
            gridArea.setX(0);
            gridArea.setY( gridArea.getY() + 32); /*ACA VA LO DEL YAML CREO (tile height).*/ 
        }
    }
    selectedTile.render(selectedArea);
}

bool Editor:: handleEvents(){
    return eventHandler.handleEvents(tiles,optionTiles);
}

void Editor::fillTileOptionList(){
    //for( int i=0; i<75 ; i++){      /* aca deberia ir LOS TOTAL SPRITES */
    optionTiles.push_back(new Tile(49,0,500,image));
    optionTiles.push_back(new Tile(5,48,500,image));
    optionTiles.push_back(new Tile(4,96,500,image));
    optionTiles.push_back(new Tile(23,144,500,image));  
    
    //}
}

Editor::~Editor(){
    for(auto& tile : optionTiles){
        delete tile;
    }

    for(auto& tile : tiles){
        delete tile;
    }
}