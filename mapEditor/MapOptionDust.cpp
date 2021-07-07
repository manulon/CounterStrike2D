#include "MapOptionDust.h"
#include <iostream>

MapOptionDust:: MapOptionDust(Window& window): 
MenuOption("assets/gfx/buttons/ButtonDust.png",window,250,25,239,32),
window(window),path(""){
    YAML::Node readerNode = YAML::LoadFile("editor_config.yaml");
    path = readerNode["config"]["dust_path"].as<std::string>();
}

MapOptionDust::~MapOptionDust(){}

const char* MapOptionDust:: getPathToImage(){
    return path.c_str();            // Tiene que estar en YAML config
}

const char* MapOptionDust::getMapName(){
    return "dust";
}

void MapOptionDust::render(){
    button.render(buttonArea);
}

bool MapOptionDust::clicked(std::vector<MenuOption*>& options){
    return false;
}

void MapOptionDust::setPair(std::pair<int,int>& pair){}

bool MapOptionDust::mouseInButton(int x, int y){
    if ( (x > buttonArea.getX() && x < (buttonArea.getX() + buttonArea.getWidth()) &&
         (y > buttonArea.getY() && y < (buttonArea.getY() + buttonArea.getHeight())) )) {
         return true;
    }
    return false;
}