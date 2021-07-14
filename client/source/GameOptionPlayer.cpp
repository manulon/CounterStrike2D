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
 	std::cout<<"Por favor, ingrese uno de los numeros de opciones de mapa."<<std::endl;

 	YAML::Node reader = YAML::LoadFile("../assets/maps/map_names.yaml");
 	
    for (long unsigned int i=3; i<reader["mapName"].size(); i++){
        std::string filter("../assets/maps/");
        std::string str(reader["mapName"][i].as<std::string>());

        int finalSize((int)str.size() - (int)filter.size() - 5);
        std::string final("",finalSize);

        for (int i=(int)filter.size(); i<(int)str.size(); i++){ 
            final[i - ((int)filter.size()) ] = str[i];
        }

 		std::cout<<i-2<<") "<<final<<std::endl;
 	}

    std::string input("");
    while (input == ""){
    	std::cin >> input;
    }

    path = reader["mapName"][stoi(input)+2].as<std::string>();

    YAML::Node reader2= YAML::LoadFile(path);
    std::string mapName(reader2["style"].as<std::string>());
    tiles = "../assets/gfx/tiles/default_"+mapName+".png";
}
