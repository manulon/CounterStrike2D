#include "ButtonMisc.h"
#include <iostream>

ButtonMisc:: ButtonMisc(Window& window,EditorConfig& editor): 
Button("../assets/gfx/buttons/ButtonMisc.png",window,editor,
        window.getWidth()-275,window.getHeight()-82,80,32),
window(window){}

ButtonMisc::~ButtonMisc(){}

void ButtonMisc::render(){
    button.render(buttonArea);
}

bool ButtonMisc::clicked(std::vector<Tile*>& options,std::vector<Tile*>& obstaclesOptionTiles,
                         std::vector<Tile*>& soldierOptionsTiles, const Image& image, 
                         const Image& obsImage,const std::string& sizeName,
                         const Image& tImage,const Image& ctImage){
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

    editor.getAtributes("misc",sizeName,options,obstaclesOptionTiles,soldierOptionsTiles,
                        image,obsImage,tImage,ctImage);

    return false;
}