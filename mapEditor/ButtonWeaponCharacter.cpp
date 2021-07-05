#include "ButtonWeaponCharacter.h"
#include <iostream>

ButtonWeaponCharacter:: ButtonWeaponCharacter(Window& window,EditorConfig& editor): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Armas/Personajes",window,editor),
window(window){}

ButtonWeaponCharacter::~ButtonWeaponCharacter(){}

void ButtonWeaponCharacter::render(){
    Area renderArea(window.getWidth()-150,window.getHeight()-55,140,25);
    textBox.render(renderArea);
}

bool ButtonWeaponCharacter::clicked(std::vector<Tile*>& options,std::vector<Tile*>& obstaclesOptionTiles,
                            		const Image& image,const Image& obsImage,const std::string& sizeName){
    std::cout<<"Clickee duo"<< std::endl;
    return false;
}