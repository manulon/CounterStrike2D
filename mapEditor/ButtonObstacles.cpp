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

bool ButtonObstacles::clicked(std::vector<Tile*>& options,const Image& image,
							  const std::string& sizeName){
    std::cout<<"Clickee obstaculos"<< std::endl;
    return false;
}