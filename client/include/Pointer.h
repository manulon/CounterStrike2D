#ifndef _POINTER_H_
#define _POINTER_H_
#include "Image.h"
#include "Area.h"



class Pointer{
    private:
        Image image;
        int x ,y;

    public:
        Pointer(const char *pathImg, Window &window, Color key);
        ~Pointer(){}
        void render();
        void set(int xx, int yy);
};



#endif