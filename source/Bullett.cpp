#include "Bullett.h"
#include <iostream>
#define PPM 32

Bullett::Bullett(std::string imgPath, Window &window) : DynamicObject(5,5),image(imgPath.c_str(),window){ }

Bullett::~Bullett() { }


void Bullett::render(int otherX, int otherY){// other representa la pos del jugador principal
    Area dest = DynamicObject::getDest(otherX,otherY);
    image.render(dest);
}