#include "ButtonWeaponCharacter.h"
#include <iostream>

ButtonWeaponCharacter:: ButtonWeaponCharacter(Window& window,EditorConfig& editor): 
Button("../assets/gfx/buttons/ButtonDuo.png",window,editor,
        window.getWidth()-235,window.getHeight()-45,122,32),
window(window){}

ButtonWeaponCharacter::~ButtonWeaponCharacter(){}

void ButtonWeaponCharacter::render(){
    button.render(buttonArea);
}

bool ButtonWeaponCharacter::clicked(std::vector<Tile*>& options,std::vector<Tile*>& obstaclesOptionTiles,
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
    
    editor.getAtributes("characters",sizeName,options,obstaclesOptionTiles,soldierOptionsTiles,
                        image,obsImage,tImage,ctImage);

    return false;
}