#include "ButtonObstacles.h"
#include <iostream>

ButtonObstacles:: ButtonObstacles(Window& window,EditorConfig& editor): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Obstaculos",window,editor),
window(window){}

ButtonObstacles::~ButtonObstacles(){}

void ButtonObstacles::render(){
    Area renderArea(600,515,125,25);
    textBox.render(renderArea);
}

bool ButtonObstacles::clicked(std::vector<Tile*>& options,const Image& image){
    std::cout<<"Clickee obstaculos"<< std::endl;
    return false;
}