#include "ButtonFloor.h"
#include <iostream>

ButtonFloor:: ButtonFloor(Window& window,EditorConfig& editor): 
Button("assets/gfx/fonts/liberationsans.ttf",40,"Pisos",window,editor),
window(window){}

ButtonFloor::~ButtonFloor(){}

void ButtonFloor::render(){
    Area renderArea(600,485,70,25);
    textBox.render(renderArea);
}

bool ButtonFloor::clicked
(std::vector<Tile*>& options, const Image& image){
    for (auto& option: options){
        delete option;
        options.pop_back();
    }

    editor.getAtributes("floor",options,image);

    /*--- PARA AZTEC ---*/
    /*options.push_back(new Tile(2,0,500,image));
    options.push_back(new Tile(3,48,500,image));
    options.push_back(new Tile(4,98,500,image));
    options.push_back(new Tile(38,148,500,image));
    options.push_back(new Tile(39,0,548,image));
    options.push_back(new Tile(43,48,548,image));
    options.push_back(new Tile(44,98,548,image));*/

    /*--- PARA DUST ---*/
    /*options.push_back(new Tile(2,0,500,image));
    options.push_back(new Tile(51,0,548,image));
    options.push_back(new Tile(52,48,500,image));
    options.push_back(new Tile(53,48,548,image));
    options.push_back(new Tile(54,98,500,image));   
    options.push_back(new Tile(55,98,548,image));
    options.push_back(new Tile(56,146,500,image));
    options.push_back(new Tile(57,146,548,image));
    options.push_back(new Tile(58,194,548,image));
    options.push_back(new Tile(59,194,500,image));
    options.push_back(new Tile(60,242,500,image));*/

    /*--- PARA INFERNO ---*/
    /*options.push_back(new Tile(2,0,500,image));
    options.push_back(new Tile(5,0,548,image));
    options.push_back(new Tile(58,48,500,image));
    options.push_back(new Tile(59,48,548,image));
    options.push_back(new Tile(60,98,500,image));   
    options.push_back(new Tile(61,98,548,image));
    options.push_back(new Tile(62,146,500,image));
    options.push_back(new Tile(63,146,548,image));
    options.push_back(new Tile(64,194,548,image));
    options.push_back(new Tile(65,194,500,image));
    options.push_back(new Tile(66,242,500,image));
    options.push_back(new Tile(67,242,548,image));
    options.push_back(new Tile(68,290,500,image));
    options.push_back(new Tile(69,290,548,image));
    options.push_back(new Tile(70,338,500,image));*/

    return false;
}