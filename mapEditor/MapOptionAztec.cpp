#include "MapOptionAztec.h"
#include <iostream>
#include <unistd.h>


MapOptionAztec:: MapOptionAztec(Window& window): 
MenuOption("assets/gfx/buttons/ButtonAztec.png",window,250,60,239,32),
window(window),path(""){
    YAML::Node readerNode = YAML::LoadFile("editor/editor_config.yaml");
    path = readerNode["config"]["aztec_path"].as<std::string>();
}

MapOptionAztec::~MapOptionAztec(){}

const char* MapOptionAztec:: getPathToImage(){
    return path.c_str();            // Tiene que estar en YAML config
}

const char* MapOptionAztec::getMapName(){
    return "aztec";
}

void MapOptionAztec::render(){
    button.render(buttonArea);
}

bool MapOptionAztec::clicked(std::vector<MenuOption*>& options){
    return false;
}

void MapOptionAztec::setPair(std::pair<int,int>& pair){}

bool MapOptionAztec::mouseInButton(int x, int y){
    if ( (x > buttonArea.getX() && x < (buttonArea.getX() + buttonArea.getWidth()) &&
         (y > buttonArea.getY() && y < (buttonArea.getY() + buttonArea.getHeight())) )) {
         return true;
    }
    return false;
}