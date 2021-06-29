#include "MenuEditorEventHandler.h"

MenuEditorEventHandler::MenuEditorEventHandler(){}

bool MenuEditorEventHandler::handleEvents(){
    SDL_Event event;

    while (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_MOUSEMOTION:
                mouseMotionHandler();
                break;

            case SDL_MOUSEBUTTONDOWN:
                mouseMotionDown();
                break;

            case SDL_MOUSEBUTTONUP:
                mouseMotionUp();
                break;

            case SDL_QUIT:
                return false;
            }
    }
    return true;
}


void MenuEditorEventHandler::mouseMotionHandler(){}

void MenuEditorEventHandler::mouseMotionDown(){}

void MenuEditorEventHandler::mouseMotionUp(){}

MenuEditorEventHandler::~MenuEditorEventHandler(){}