#include "GameOptionAztec.h"

GameOptionAztec::GameOptionAztec(Window &window):
GameOption("../assets/gfx/buttons/InitialMenuAztec.png",window,
           205,0,200,32){}

GameOptionAztec::~GameOptionAztec(){}

bool GameOptionAztec::clicked(std::vector<GameOption*>& options){
    return false;
}

void GameOptionAztec::setPath(std::string& path,std::string& tiles){
    path = "../assets/maps/BigAztec.yaml";
    tiles = "../assets/gfx/tiles/default_aztec.png";
}