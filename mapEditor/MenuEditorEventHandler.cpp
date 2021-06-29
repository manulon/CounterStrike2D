#include "MenuEditorEventHandler.h"
#include <iostream>
#include <utility>

MenuEditorEventHandler::MenuEditorEventHandler(): 
mousePositionX(0),mousePositionY(0){}

bool MenuEditorEventHandler::handleEvents(std::vector<Text*>& options){
    SDL_Event event;

    while (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_MOUSEMOTION:
                mouseMotionHandler(event,options);
                break;

            case SDL_MOUSEBUTTONDOWN:
                mouseMotionDown(event);
                break;

            case SDL_MOUSEBUTTONUP:
                mouseMotionUp(event);
                break;

            case SDL_QUIT:
                return false;
            }
    }
    return true;
}


void MenuEditorEventHandler::mouseMotionHandler
(SDL_Event& event,std::vector<Text*>& options){
    mousePositionX = event.motion.x;
    mousePositionY = event.motion.y;
    for(auto& option: options){
        if (option->mouseInText(mousePositionX,mousePositionY)){
            std::cout<<"Mouse arriba de una opcion"<< std::endl;
        }
    }
}

void MenuEditorEventHandler::mouseMotionDown(SDL_Event& event){}

void MenuEditorEventHandler::mouseMotionUp(SDL_Event& event){}

MenuEditorEventHandler::~MenuEditorEventHandler(){}