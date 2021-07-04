#include "RenderizableFactory.h"
#include "Soldier.h"
#include "Image.h"
#include "Weapon.h"
#define SOLDIER 0
#define AK47 1
RenderizableFactory::RenderizableFactory(Window & window) : window(window){}

DynamicObject* RenderizableFactory::createRenderizable(short id){
    if (id == SOLDIER){
        return (new Soldier("assets/gfx/player/t1.bmp",window));
    } else if (id == AK47){    
        return(new Weapon("assets/gfx/weapons/ak47_d.bmp",window,16,32));
    }
    return NULL;
}