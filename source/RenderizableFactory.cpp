#include "RenderizableFactory.h"
#include "Soldier.h"
#include "Image.h"
#include "Weapon.h"
#define SOLDIER 0
#define AK47 1
RenderizableFactory::RenderizableFactory(Window & window) : window(window){}

DynamicObject* RenderizableFactory::createRenderizable(short id){
    std::cout << "entro a la factoria\n";
    if (id == SOLDIER){
        // Image soldier_img1("assets/gfx/player/t1.bmp", window);
        return (new Soldier("assets/gfx/player/t1.bmp",window));
        // return soldier; 
    } else if (id == AK47){    
        // Image weaponImg("assets/gfx/weapons/ak47_d.bmp",window);
        return(new Weapon("assets/gfx/weapons/ak47_d.bmp",window,16,32));
        // return weapon;
    }
    return NULL;
}