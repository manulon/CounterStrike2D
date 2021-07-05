#include "ButtonMisc.h"
#include <iostream>

ButtonMisc:: ButtonMisc(Window& window,EditorConfig& editor): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Misc",window,editor),
window(window){}

ButtonMisc::~ButtonMisc(){}

void ButtonMisc::render(){
    Area renderArea(window.getWidth()-275,window.getHeight()-80,70,25);
    textBox.render(renderArea);
}

bool ButtonMisc::clicked(std::vector<Tile*>& options,const Image& image,
						 const std::string& sizeName){
    for (auto& option: options){
        delete option;
        options.pop_back();
    }

    editor.getAtributes("misc",sizeName,options,image);

    return false;
}