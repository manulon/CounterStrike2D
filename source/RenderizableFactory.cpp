#include "RenderizableFactory.h"
#include "Soldier.h"
#include "Image.h"
#include "Weapon.h"
#define SOLDIER 0
#define AK47 1
RenderizableFactory::RenderizableFactory(Window & window) : window(window){}

bool RenderizableFactory::createRenderizable(short id, std::map<short,DynamicObject*> &objects){
    if (isPresent(id,objects)) return true;
    if (isSoldier(id)){
        objects[id] = new Soldier("assets/gfx/player/t1.bmp",window);
        return true;
    } else if (isAk47(id)){    
        objects[id] = new Weapon("assets/gfx/weapons/ak47_d.bmp",window,16,32);
        return true;
    }
    return false;
}

bool RenderizableFactory::isPresent(short id, std::map<short,DynamicObject*> &objects){
    if (objects.find(id) == objects.end()){
        return false;
    }
    return true;
}
bool RenderizableFactory::isSoldier(short id){
    if (id >=0 && id < 10)
        return true;
    return false;
}

bool RenderizableFactory::isAk47(short id){
    if (id >= 10 && id < 20)
        return true;
    return false;
}