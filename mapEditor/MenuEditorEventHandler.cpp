#include "MenuEditorEventHandler.h"
#include <iostream>
#include <utility>

MenuEditorEventHandler::MenuEditorEventHandler(): 
mousePositionX(0),mousePositionY(0),path(){}

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
            std::cout<<"Aprete una opcion "<< std::endl;
            if (option->getPathToImage() != nullptr)
                path = option->getPathToImage();
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

MenuEditorEventHandler::~MenuEditorEventHandler(){}