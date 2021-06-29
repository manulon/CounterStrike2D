#include "EditorMenu.h"

EditorMenu::EditorMenu():
textColor(0, 0, 0),
window("Menu Editor", 300, 150, SDL_WINDOW_RESIZABLE, 
       SDL_INIT_VIDEO | SDL_INIT_AUDIO),
textSelectMode("assets/gfx/fonts/liberationsans.ttf", 40,
               "Seleccionar modo ", textColor.getColor(), window),
textExit("assets/gfx/fonts/liberationsans.ttf", 40,
         "Salir ", textColor.getColor(), window)
{}

void EditorMenu::render(){
    Area selectedModeArea(0, 25, 150, 40);
    Area exitArea(0, 75, 100, 30);              

    textSelectMode.render(selectedModeArea);
    textExit.render(exitArea);
    window.render();
}

void EditorMenu::close(){
    window.changeWindow();
}

EditorMenu::~EditorMenu(){}