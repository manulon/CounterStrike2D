#include "MenuEditorEventHandler.h"
#include <iostream>
#include <utility>

MenuEditorEventHandler::MenuEditorEventHandler(): 
mousePositionX(0),mousePositionY(0),path("no_path"),mapName(""){}

bool MenuEditorEventHandler::handleEvents(std::vector<MenuOption*>& options){
    SDL_Event event;

    while (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_MOUSEMOTION:
                return mouseMotionHandler(event,options);

            case SDL_MOUSEBUTTONDOWN:
                return mouseMotionDown(event,options);

            case SDL_MOUSEBUTTONUP:
                return mouseMotionUp(event);

            case SDL_QUIT:
                path = "no path";
                return false;
            }
    }
    return true;
}


bool MenuEditorEventHandler::mouseMotionHandler
(SDL_Event& event,std::vector<MenuOption*>& options){
    mousePositionX = event.motion.x;
    mousePositionY = event.motion.y;
    for(auto& option: options){
        if (option->mouseInText(mousePositionX,mousePositionY)){
            //option->changeColor(255,250,0);
        }
    }
    return true;
}

bool MenuEditorEventHandler::mouseMotionDown
(SDL_Event& event,std::vector<MenuOption*>& options){
    for(auto& option: options){
        if (option->mouseInText(mousePositionX,mousePositionY)){
            if (option->getPathToImage() != nullptr){
                path = option->getPathToImage();
                mapName = option->getMapName();
            }else{
                path = "no path";
            }
            return option->clicked(options);
        }
    }
    return true;
}

bool MenuEditorEventHandler::mouseMotionUp(SDL_Event& event){
    return true;
}

std::string& MenuEditorEventHandler::getPath(){
    return path;
}

std::string& MenuEditorEventHandler::getMapName(){
    return mapName;
}

MenuEditorEventHandler::~MenuEditorEventHandler(){}