#include "EditorMenu.h"
#include <iostream>
#include <string>

EditorMenu::EditorMenu():
window("Menu Editor", 500, 200, SDL_WINDOW_RESIZABLE, 
       SDL_INIT_VIDEO | SDL_INIT_AUDIO),
textSelectMode("assets/gfx/fonts/liberationsans.ttf", 40,
               "Seleccionar modo ",window),
textExit("assets/gfx/fonts/liberationsans.ttf", 40,
         "Salir ", window),
handler(),startEditor(true),selectorMenu(),pairSize(0,0){
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
    if (getPath() != NULL_PATH)
        selectorMenu.run();
    pairSize = selectorMenu.getPair();
}

void EditorMenu::clear(){
    window.clear();
}

bool EditorMenu::handleEvents(){
    bool keepRunning(false);
    keepRunning = handler.handleEvents(options);
    if (getPath() == NULL_PATH){
        startEditor=false;
    }
    return keepRunning;
}

std::string EditorMenu::getPath(){
    return handler.getPath();
}

bool EditorMenu:: runEditor(){
    return startEditor;
}

const char* EditorMenu::getMapName(){
    return handler.getMapName().c_str();
}

std::pair<int,int>& EditorMenu::getSize(){
    return pairSize;
}

EditorMenu::~EditorMenu(){}