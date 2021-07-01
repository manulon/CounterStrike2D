#include "ButtonWeaponCharacter.h"
#include <iostream>

ButtonWeaponCharacter:: ButtonWeaponCharacter(Window& window): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Armas/Personajes",window),
window(window){}

ButtonWeaponCharacter::~ButtonWeaponCharacter(){}

void ButtonWeaponCharacter::render(){
    Area renderArea(642,625,100,30);
    textBox.render(renderArea);
}

bool ButtonWeaponCharacter::clicked(){
    return false;
}