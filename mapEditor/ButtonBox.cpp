#include "ButtonBox.h"
#include <iostream>

ButtonBox:: ButtonBox(Window& window,EditorConfig& editor): 
Button("assets/gfx/buttons/ButtonBox.png",window,editor,
        window.getWidth()-275,window.getHeight()-115,80,32),
window(window){}

ButtonBox::~ButtonBox(){}

void ButtonBox::render(){
    button.render(buttonArea);
}

bool ButtonBox::clicked(std::vector<Tile*>& options,std::vector<Tile*>& obstaclesOptionTiles,
                        const Image& image,const Image& obsImage,const std::string& sizeName){
    for (auto& option: options){
        delete option;
        options.pop_back();
    }

    for (auto& option: obstaclesOptionTiles){
        delete option;
        obstaclesOptionTiles.pop_back();
    }

    editor.getAtributes("box",sizeName,options,obstaclesOptionTiles,image,obsImage);
    
    return false;
}