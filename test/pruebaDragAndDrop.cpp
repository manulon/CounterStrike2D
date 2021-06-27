#include "EditorEventHandler.h"
#include "Editor.h"
#include "Window.h"
#include "Image.h"
#include <iostream>
#include <unistd.h>


bool leftMouseButtonDown = false;

int main(int argc, const char *argv[]){
	Window window("Counter Strike 2D", 800, 600, 
                      SDL_WINDOW_RESIZABLE, 
                      SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    Image de_dust("assets/gfx/tiles/default_dust.png", window);
    Area area(0, 0, 32, 32);

    Editor editor(window);
    EditorEventHandler mapEditor(area,window);

    Image grid("assets/gfx/emptySpace.png", window);
    

    bool running(true);
    while (running) {
    	window.clear();
        editor.showGrid();    	
        running = mapEditor.handleEvents();
	    de_dust.render(area);
	    window.render();
	}
    
	return 0;
}
