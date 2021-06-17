#include "Dot.h"
#include <iostream>

Dot:: Dot(Image const& img):
img(img),x(0),y(0){}

Dot:: ~Dot(){}

void Dot::move(int direction){
    if (direction == 2) {
        x += 3;
    }else if (direction == 3) {
        x -= 3;
    }
}


void Dot::render(const Area &dest){
    img.render(x,y,dest);
}
