#include "ButtonWeaponCharacter.h"
#include <iostream>

ButtonWeaponCharacter:: ButtonWeaponCharacter(Window& window): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Armas/Personajes",window),
window(window){}

ButtonWeaponCharacter::~ButtonWeaponCharacter(){}

void ButtonWeaponCharacter::render(){
    Area renderArea(600,550,140,25);
    textBox.render(renderArea);
}

bool ButtonWeaponCharacter::clicked(){
    std::cout<<"Clickee duo"<< std::endl;
    return false;
}