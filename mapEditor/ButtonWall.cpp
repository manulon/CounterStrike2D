#include "ButtonWall.h"
#include <iostream>

ButtonWall:: ButtonWall(Window& window,EditorConfig& editor): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Paredes",window,editor),
window(window){}

ButtonWall::~ButtonWall(){}

void ButtonWall::render(){
    Area renderArea(window.getWidth()-275,window.getHeight()-55,90,25);
    textBox.render(renderArea);
}

bool ButtonWall::clicked(std::vector<Tile*>& options,const Image& image){
    for (auto& option: options){
        delete option;
        options.pop_back();
    }
    
    editor.getAtributes("wall",options,image);

    return false;
}