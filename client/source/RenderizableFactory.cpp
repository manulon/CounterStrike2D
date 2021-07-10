#include "RenderizableFactory.h"
#include "Soldier.h"
#include "Image.h"
#include "Weapon.h"
#include "Bullett.h"
#define SOLDIER 0
#define AK47 1
RenderizableFactory::RenderizableFactory(Window & window) : window(window){}

bool RenderizableFactory::createRenderizable(short id, std::map<short,std::unique_ptr<DynamicObject>> &objects){
    if (isPresent(id,objects)) return true;
    if (isSoldier(id)){
        std::unique_ptr<DynamicObject> ptr(new Soldier("../assets/gfx/player/t1.bmp",window));
        objects[id] = std::move(ptr);
        return true;
    } else if (isAk47(id)){    
        std::unique_ptr<DynamicObject> ptr(new Weapon("../assets/gfx/weapons/ak47_d.bmp",window,16,32));
        objects[id] = std::move(ptr);
        return true;
    }  else if (id == 60){
        std::unique_ptr<DynamicObject> ptr(new Bullett("../assets/gfx/bullet.png",window));
        objects[id] = std::move(ptr); 
        return true;
    }
    return false;
}

bool RenderizableFactory::isPresent(short id, std::map<short,std::unique_ptr<DynamicObject>> &objects){
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