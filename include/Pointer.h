#ifndef _POINTER_H_
#define _POINTER_H_
#include "Image.h"
#include "Area.h"



class Pointer{
    private:
        const Image &image;

    public:
        Pointer(const Image &img);
        ~Pointer(){}
        void render(float x, float y);
};



#endif