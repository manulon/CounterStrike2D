#include "EditorEventHandler.h"
#include "Editor.h"
#include "Window.h"
#include "Tile.h"
#include "Text.h"
#include "EditorMenu.h"
#include <iostream>
#include <unistd.h>

int main(int argc, const char *argv[]){
    EditorMenu menu;
    menu.render();
    usleep(4000000);
    menu.close(); 

    Window window("Counter Strike 2D", 800, 600, 
                  SDL_WINDOW_RESIZABLE, 
                  SDL_INIT_VIDEO | SDL_INIT_AUDIO);

     /* ------------------------------------- */
    Image de_dust("assets/gfx/backgroundTest.png", window);
    Tile tilexx(1,1,1,de_dust);
    SdlColor colorcito(0,0,0);
    Text textcito("assets/gfx/fonts/liberationsans.ttf", 40,"DFA",colorcito.getColor(),window);
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
