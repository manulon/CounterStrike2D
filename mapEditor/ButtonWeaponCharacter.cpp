#include "ButtonWeaponCharacter.h"
#include <iostream>

ButtonWeaponCharacter:: ButtonWeaponCharacter(Window& window,EditorConfig& editor): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Armas/Personajes",window,editor),
window(window){}

ButtonWeaponCharacter::~ButtonWeaponCharacter(){}

void ButtonWeaponCharacter::render(){
    Area renderArea(600,550,140,25);
    textBox.render(renderArea);
}

bool ButtonWeaponCharacter::clicked(std::vector<Tile*>& buttons,const Image& image){
    std::cout<<"Clickee duo"<< std::endl;
    return false;
}