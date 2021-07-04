#include "ButtonFloor.h"
#include <iostream>

ButtonFloor:: ButtonFloor(Window& window,EditorConfig& editor): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Pisos",window,editor),
window(window){}

ButtonFloor::~ButtonFloor(){}

void ButtonFloor::render(){
    Area renderArea(window.getWidth()-150,window.getHeight()-105,70,25);
    textBox.render(renderArea);
}

bool ButtonFloor::clicked
(std::vector<Tile*>& options, const Image& image){
    for (auto& option: options){
        delete option;
        options.pop_back();
    }

    editor.getAtributes("floor",options,image);

    return false;
}