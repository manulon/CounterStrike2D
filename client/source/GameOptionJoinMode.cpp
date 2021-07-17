#include "GameOptionJoinMode.h"

GameOptionJoinMode:: GameOptionJoinMode(Window& window): 
GameOption("../assets/gfx/buttons/buttonJoinGame.png",window,
           0,64,195,32), window(window){}

bool GameOptionJoinMode::clicked(std::vector<GameOption*>& options){
    options.push_back(new GameOptionAztec(window));
    options.push_back(new GameOptionDust(window));
    options.push_back(new GameOptionInferno(window));
    options.push_back(new GameOptionPlayer(window));
    return true;
}

void GameOptionJoinMode::setPath(std::string& path, std::string& tiles){}

GameOptionJoinMode::~GameOptionJoinMode(){}

