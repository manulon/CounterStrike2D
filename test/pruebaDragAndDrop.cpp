#include "EditorEventHandler.h"
#include "Editor.h"
#include "Window.h"
#include "Tile.h"
#include <iostream>
#include <unistd.h>

int main(int argc, const char *argv[]){
	Window window("Counter Strike 2D", 800, 600, 
                      SDL_WINDOW_RESIZABLE, 
                      SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    /* SI BORRAS ESTAS LINEAS SE ROMPE TODO. */
    Image de_dust("assets/gfx/backgroundTest.png", window);
    Tile tilexx(1,1,1,de_dust);
    /*---------------------------------------*/
    
    Editor editor(window);
    editor.fillTileOptionList();
    
    bool running(true);
    while (running) {
    	window.clear();
        editor.showGrid();    	
        running = editor.handleEvents();
	    window.render();
	}
    
	return 0;
}
