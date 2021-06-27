#include "Editor.h"
#include <iostream>
#include <unistd.h>


Editor::Editor(Window& window): 
window(window),grid("assets/gfx/emptySpace.png", window),
image("assets/gfx/tiles/default_dust.png", window),area(0,0,32,32),
eventHandler(area, window){}

void Editor:: showGrid(){    
    Area gridArea(0, 0, 32, 32);
    while ( gridArea.getY()< (window.getHeight() - 128) ){ /* CONSTANTE EL 128 */
        grid.render(gridArea);
    
        gridArea.setX( gridArea.getX() + 32); /*ACA VA LO DEL YAML CREO (tile width).*/

        if ( gridArea.getX()>window.getWidth() ){
            gridArea.setX(0);
            gridArea.setY( gridArea.getY() + 32); /*ACA VA LO DEL YAML CREO (tile height).*/ 
        }
    }
}

void Editor:: renderImageTest(){
    image.render(area);
}

bool Editor:: handleEvents(){
    return eventHandler.handleEvents();
}

Editor::~Editor(){}