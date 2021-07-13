#include "GameOptionExit.h"

GameOptionExit::GameOptionExit(Window& window): 
GameOption("../assets/gfx/buttons/InitialMenuSalir.png",window,
           0,112,195,32){}

bool GameOptionExit::clicked(std::vector<GameOption*>& options){
    return false;
}

void GameOptionExit::setPath(std::string& path, std::string& tiles){}

GameOptionExit::~GameOptionExit(){}
