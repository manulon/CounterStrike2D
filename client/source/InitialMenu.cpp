#include "InitialMenu.h"
#include "GameOptionExit.h"
#include "GameOptionJoinMode.h"

InitialMenu::InitialMenu():
window("Menu Inicial", 500, 200, SDL_WINDOW_RESIZABLE, 
       SDL_INIT_VIDEO | SDL_INIT_AUDIO), handler(){
    setInitialButtons();
}

InitialMenu::~InitialMenu(){}

void InitialMenu::close(){
    window.changeWindow();
}

void InitialMenu::clear(){
    window.clear();
}

void InitialMenu::setInitialButtons(){
    buttons.push_back(new GameOptionExit(window));
    buttons.push_back(new GameOptionJoinMode(window));
}

void InitialMenu::render(){
    for (auto& button: buttons){
        button->render();
    }
    window.render();
}

bool InitialMenu::handleEvents(){
    return handler.handleEvents(buttons);
}

std::string& InitialMenu::getMapPath(){
    return handler.getMapPath();
}

std::string& InitialMenu::getTilesPath(){
    return handler.getTilesPath();
}

bool InitialMenu::startGame(){
    if (handler.getMapPath() == "")
        return false;
    return true;
}
