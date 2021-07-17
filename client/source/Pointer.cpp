#include "Pointer.h"

Pointer::Pointer(const char *pathImg, Window &window, Color key) : image(pathImg,window,key),x(0),y(0) { }

void Pointer::render(){
    Area dest(x-10, y-10, 20,20);
    Area src(0,0,46,46);
    image.render(src,dest);
}
void Pointer::set(int xx, int yy){
    x = xx; 
    y = yy;
}