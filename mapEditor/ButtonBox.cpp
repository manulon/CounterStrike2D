#include "ButtonBox.h"
#include <iostream>

ButtonBox:: ButtonBox(Window& window,EditorConfig& editor): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Cajas",window,editor),
window(window){}

ButtonBox::~ButtonBox(){}

void ButtonBox::render(){
    Area renderArea(window.getWidth()-275,window.getHeight()-105,70,25);
    textBox.render(renderArea);
}

bool ButtonBox::clicked(std::vector<Tile*>& options,const Image& image,
						const std::string& sizeName){
    for (auto& option: options){
        delete option;
        options.pop_back();
    }

    editor.getAtributes("box",sizeName,options,image);
    
    return false;
}