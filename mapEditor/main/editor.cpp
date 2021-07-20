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
        Editor editor(menu.getPath().c_str(),menu.getMapName(),menu.getSize());
        editor.fillTileOptionList();
    
        bool runningEditor(true);
        while (runningEditor) {
            editor.clearWindow();
            editor.showGrid();    	
            runningEditor = editor.handleEvents();
            editor.render();
        }
        return 0;
    }   

    return 0;
}
