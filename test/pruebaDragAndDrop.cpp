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
    
    bool runningMenu(true);
    while (runningMenu) {
    	menu.clear();    	
        runningMenu = menu.handleEvents();
	    menu.render();
	}
    menu.close(); 
        

    if (menu.runEditor()){
        Window window("Counter Strike 2D", menu.getWidth(), menu.getHeight(), 
                    SDL_WINDOW_RESIZABLE, 
                    SDL_INIT_VIDEO | SDL_INIT_AUDIO);

        Editor editor(window,menu.getPath().c_str(),menu.getMapName(),menu.getSize());
        editor.fillTileOptionList();
    
        bool runningEditor(true);
        while (runningEditor) {
            window.clear();
            editor.showGrid();    	
            runningEditor = editor.handleEvents();
            window.render();
        }
        return 0;
    }

    return 0;
}
