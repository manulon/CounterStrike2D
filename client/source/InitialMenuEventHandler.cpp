#include "InitialMenuEventHandler.h"
#include <iostream>
#include <utility>

InitialMenuEventHandler::InitialMenuEventHandler(): 
mousePositionX(0), mousePositionY(0), mapPath(""), tilesPath(""){}

bool InitialMenuEventHandler::handleEvents(std::vector<GameOption*>& options){
    SDL_Event event;

    while (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_MOUSEMOTION:
                return mouseMotionHandler(event,options);

            case SDL_MOUSEBUTTONDOWN:
                return mouseMotionDown(event,options);

            case SDL_QUIT:
                return false;
            }
    }
    return true;
}


bool InitialMenuEventHandler::mouseMotionHandler
(SDL_Event& event,std::vector<GameOption*>& options){
    mousePositionX = event.motion.x;
    mousePositionY = event.motion.y;
    return true;
}

bool InitialMenuEventHandler::mouseMotionDown
(SDL_Event& event,std::vector<GameOption*>& options){
    for (auto& option: options){
        if (option->mouseInButton(mousePositionX,mousePositionY)){
            option->setPath(mapPath,tilesPath);
            return option->clicked(options);
        }
    }
    return true;
}

std::string& InitialMenuEventHandler::getMapPath(){
    return mapPath;
}

std::string& InitialMenuEventHandler::getTilesPath(){
    return tilesPath;
}

InitialMenuEventHandler::~InitialMenuEventHandler(){}