#include "GameOptionInferno.h"

GameOptionInferno::GameOptionInferno(Window &window):
GameOption("../assets/gfx/buttons/InitialMenuInferno.png",window,
           205,96,200,32){}

GameOptionInferno::~GameOptionInferno(){}

bool GameOptionInferno::clicked(std::vector<GameOption*>& options){
    return false;
}

void GameOptionInferno::setPath(std::string& path, std::string& tiles){
    path = "../assets/maps/HugeInferno.yaml";
    tiles = "../assets/gfx/tiles/default_inferno.png";
}