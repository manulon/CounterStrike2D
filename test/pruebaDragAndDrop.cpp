#include "EditorEventHandler.h"
#include "Editor.h"
#include "Window.h"
#include <iostream>
#include <unistd.h>

int main(int argc, const char *argv[]){
	Window window("Counter Strike 2D", 800, 600, 
                      SDL_WINDOW_RESIZABLE, 
                      SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    /* SI BORRAS ESTA LINEA SE ROMPE TODO. */
    Image de_dust("assets/gfx/tiles/default_dust.png", window);

    Editor editor(window);

    bool running(true);
    while (running) {
    	window.clear();
        editor.showGrid();    	
        running = editor.handleEvents();
        editor.renderImageTest();
	    window.render();
	}
    
	return 0;
}
