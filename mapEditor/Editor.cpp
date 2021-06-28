#include "Editor.h"
#include <iostream>
#include <unistd.h>
#include <utility>

Editor::Editor(Window& window): 
window(window),grid("assets/gfx/emptySpace.png", window),
image("assets/gfx/tiles/default_dust.png", window),         //el path de la imagen tiene que
eventHandler(window,image){}                                      //estar en yaml

void Editor:: showGrid(){    
    Area gridArea(0, 0, 32, 32);
    while ( gridArea.getY() < (window.getHeight() - 128) ){ /* CONSTANTE EL 128 */
        grid.render(gridArea);
    
        gridArea.setX( gridArea.getX() + 32); /*ACA VA LO DEL YAML CREO (tile width).*/

        if ( gridArea.getX()>window.getWidth() ){
            gridArea.setX(0);
            gridArea.setY( gridArea.getY() + 32); /*ACA VA LO DEL YAML CREO (tile height).*/ 
        }
    }
}

bool Editor:: handleEvents(){
    return eventHandler.handleEvents(tiles);
}

void Editor::fillTileOptionList(){
    //for( int i=0; i<75 ; i++){      /* aca deberia ir LOS TOTAL SPRITES */
    
    tiles.push_back(new Tile(49,0,500,image));
    tiles.push_back(new Tile(5,48,500,image));
    tiles.push_back(new Tile(4,96,500,image));
    tiles.push_back(new Tile(23,144,500,image));  
    //}
}

Editor::~Editor(){
    /*Se borran los tiles por ser RAII?*/
}