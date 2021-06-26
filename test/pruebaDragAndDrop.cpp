#include "EditorEventHandler.h"
#include "Window.h"
#include "Image.h"

bool leftMouseButtonDown = false;

int main(int argc, const char *argv[]){
	Window window("Counter Strike 2D", 800, 600, 
                      SDL_WINDOW_RESIZABLE, 
                      SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    Image de_dust("assets/gfx/tiles/default_dust.png", window);
    SDL_Point mousePos = {0, 0};
    Area area(0, 0, 50, 50);

    EditorEventHandler mapEditor(area,mousePos);

    bool running(true);
    while (running) {
    	window.clear();
    	running = mapEditor.handleEvents();
	    de_dust.render(area);
	    window.render();
	}
    
	return 0;
}
