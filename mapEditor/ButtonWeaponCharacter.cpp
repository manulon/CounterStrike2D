#include "ButtonWeaponCharacter.h"
#include <iostream>

ButtonWeaponCharacter:: ButtonWeaponCharacter(Window& window,EditorConfig& editor): 
Button("assets/gfx/buttons/ButtonDuo.png",window,editor,
        window.getWidth()-150,window.getHeight()-55,140,25),
window(window){}

ButtonWeaponCharacter::~ButtonWeaponCharacter(){}

void ButtonWeaponCharacter::render(){
    button.render(buttonArea);
}

bool ButtonWeaponCharacter::clicked(std::vector<Tile*>& options,std::vector<Tile*>& obstaclesOptionTiles,
                            		const Image& image,const Image& obsImage,const std::string& sizeName){
    return false;
}