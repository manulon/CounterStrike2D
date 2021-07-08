#include "Pointer.h"

Pointer::Pointer(const Image &img) : image(img) { }

void Pointer::render(float x, float y){
    Area dest(x-10, y-10, 20,20);
    Area src(0,0,46,46);
    image.render(src,dest);
}