#include "EditorMenu.h"
#include <iostream>

EditorMenu::EditorMenu():
textColor(0, 0, 0),
window("Menu Editor", 300, 150, SDL_WINDOW_RESIZABLE, 
       SDL_INIT_VIDEO | SDL_INIT_AUDIO),
textSelectMode("assets/gfx/fonts/liberationsans.ttf", 40,
               "Seleccionar modo ", textColor.getColor(), window),
textExit("assets/gfx/fonts/liberationsans.ttf", 40,
         "Salir ", textColor.getColor(), window),
handler(){
    options.push_back(&textSelectMode);
    options.push_back(&textExit);
}

void EditorMenu::render(){
    Area selectedModeArea(0, 25, 150, 40);
    Area exitArea(0, 75, 100, 30);              

    options[0]->render(selectedModeArea);
    options[1]->render(exitArea);

    window.render();
}

void EditorMenu::close(){
    window.changeWindow();
}

void EditorMenu::clear(){
    window.clear();
}

bool EditorMenu::handleEvents(){
    return handler.handleEvents(options);
}

EditorMenu::~EditorMenu(){}