#include "ButtonFloor.h"
#include <iostream>

ButtonFloor:: ButtonFloor(Window& window,EditorConfig& editor): 
Button("assets/gfx/buttons/ButtonFloor.png",window,editor,
        window.getWidth()-150,window.getHeight()-105,70,25),
window(window){}

ButtonFloor::~ButtonFloor(){}

void ButtonFloor::render(){
    button.render(buttonArea);
}

bool ButtonFloor::clicked
(std::vector<Tile*>& options,std::vector<Tile*>& obstaclesOptionTiles,
 const Image& image,const Image& obsImage,const std::string& sizeName){
    for (auto& option: options){
        delete option;
        options.pop_back();
    }

    for (auto& option: obstaclesOptionTiles){
        delete option;
        obstaclesOptionTiles.pop_back();
    }
    
    editor.getAtributes("floor",sizeName,options,obstaclesOptionTiles,image,obsImage);

    return false;
}