#include "EditorMenu.h"
#include <iostream>

EditorMenu::EditorMenu():
window("Menu Editor", 500, 200, SDL_WINDOW_RESIZABLE, 
       SDL_INIT_VIDEO | SDL_INIT_AUDIO),
textSelectMode("assets/gfx/fonts/liberationsans.ttf", 40,
               "Seleccionar modo ",window),
textExit("assets/gfx/fonts/liberationsans.ttf", 40,
         "Salir ", window),
handler(),startEditor(true){
    options.push_back(&textSelectMode);
    options.push_back(&textExit);
}

void EditorMenu::render(){
    for (auto& option: options){
        option->render();
    }

    window.render();
}

void EditorMenu::close(){
    window.changeWindow();
}

void EditorMenu::clear(){
    window.clear();
}

bool EditorMenu::handleEvents(){
    bool keepRunning(true);
    keepRunning = handler.handleEvents(options);
    if (getPath() != nullptr)
        startEditor=true;
    return keepRunning;
}

const char* EditorMenu::getPath(){
    return handler.getPath().c_str();
}

bool EditorMenu:: runEditor(){
    return startEditor;
}

EditorMenu::~EditorMenu(){}