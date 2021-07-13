#include "GameOptionDust.h"

GameOptionDust::GameOptionDust(Window &window):
GameOption("../assets/gfx/buttons/InitialMenuDust.png",window,
           205,48,200,32){}

GameOptionDust::~GameOptionDust(){}

void GameOptionDust::setPath(std::string& path,std::string& tiles){
    path = "../assets/maps/SmallDust.yaml";
    tiles = "../assets/gfx/tiles/default_dust.png";
}

bool GameOptionDust::clicked(std::vector<GameOption*>& options){
    std::cout<<"Clickee dust"<< std::endl;
    return false;
}