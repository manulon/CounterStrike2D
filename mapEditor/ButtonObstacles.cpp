#include "ButtonObstacles.h"
#include <iostream>

ButtonObstacles:: ButtonObstacles(Window& window,EditorConfig& editor): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Obstaculos",window,editor),
window(window){}

ButtonObstacles::~ButtonObstacles(){}

void ButtonObstacles::render(){
    Area renderArea(window.getWidth()-150,window.getHeight()-80,125,25);
    textBox.render(renderArea);
}

bool ButtonObstacles::clicked(std::vector<Tile*>& options,std::vector<Tile*>& obstaclesOptionTiles,
                              const Image& image,const Image& obsImage,const std::string& sizeName){
	for (auto& option: options){
        delete option;
        options.pop_back();
    }
    for (auto& option: obstaclesOptionTiles){
        delete option;
        obstaclesOptionTiles.pop_back();
    }

    editor.getAtributes("obstacles",sizeName,options,obstaclesOptionTiles,image,obsImage);

    return false;
}