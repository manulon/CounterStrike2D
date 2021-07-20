#include "ButtonFloor.h"
#include <iostream>

ButtonFloor:: ButtonFloor(Window& window,EditorConfig& editor): 
Button("../assets/gfx/buttons/ButtonFloor.png",window,editor,
        window.getWidth()-150,window.getHeight()-115,80,32),
window(window){}

ButtonFloor::~ButtonFloor(){}

void ButtonFloor::render(){
    button.render(buttonArea);
}

bool ButtonFloor::clicked
(std::vector<Tile*>& options,std::vector<Tile*>& obstaclesOptionTiles,
 std::vector<Tile*>& soldierOptionsTiles, const Image& image, 
 const Image& obsImage,const std::string& sizeName,
 const Image& tImage,const Image& ctImage, const Image& weapon){
    for (auto& option: options){
        delete option;
        options.pop_back();
    }

    for (auto& option: obstaclesOptionTiles){
        delete option;
        obstaclesOptionTiles.pop_back();
    }

    for (auto& option: soldierOptionsTiles){
        delete option;
        soldierOptionsTiles.pop_back();
    }
    
    editor.getAtributes("floor",sizeName,options,obstaclesOptionTiles,soldierOptionsTiles,
                        image,obsImage,tImage,ctImage,weapon);

    return false;
}