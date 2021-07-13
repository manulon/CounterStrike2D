#include "GameOptionSelectMode.h"

GameOptionSelectMode:: GameOptionSelectMode(Window& window): 
GameOption("../assets/gfx/buttons/InitialMenuSelected.png",window,
           0,64,195,32), window(window){}

bool GameOptionSelectMode::clicked(std::vector<GameOption*>& options){
    options.push_back(new GameOptionAztec(window));
    options.push_back(new GameOptionDust(window));
    options.push_back(new GameOptionInferno(window));
    options.push_back(new GameOptionPlayer(window));
    return true;
}

void GameOptionSelectMode::setPath(std::string& path, std::string& tiles){}

GameOptionSelectMode::~GameOptionSelectMode(){}

