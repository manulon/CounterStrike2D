#ifndef CAMERA_H 
#define CAMERA_H 

#include "Image.h"

//https://lazyfoo.net/tutorials/SDL/31_scrolling_backgrounds/index.php
//Hacerla movible pero no copiable.
class Camera{
    public:

        Camera(const Image& img);
        ~Camera();

        void move(int direction);
        void render(const Area &dest);
        int getScrollingOffset();
        int getBackgroundWidth();
        int getBackgroundHeight();

    private:
        const Image& img;
        //The X and Y offsets of the dot
        int x;
        int y;
        int scrollingOffset;
        int backgroundWidth;
        int backgroundHeight;

};


#endif