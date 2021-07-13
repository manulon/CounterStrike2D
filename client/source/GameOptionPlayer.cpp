#include "GameOptionPlayer.h"

GameOptionPlayer::GameOptionPlayer(Window &window):
GameOption("../assets/gfx/buttons/InitialMenuPlayer.png",window,
           205,144,200,32){}

GameOptionPlayer::~GameOptionPlayer(){}

bool GameOptionPlayer::clicked(std::vector<GameOption*>& options){
    std::cout<<"Clickee player"<< std::endl;
    return false;
}

void GameOptionPlayer::setPath(std::string& path, std::string& tiles){
    path = "../assets/maps/mapEditor.yaml";
    /*ESTO ESTA MAL TIENE QUE SALIR DEL YAML EL PATH A TILES*/
    tiles = "../assets/gfx/tiles/default_dust.png";
}