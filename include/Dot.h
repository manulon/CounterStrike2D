#ifndef DOT_H 
#define DOT_H 

#include "Image.h"

//https://lazyfoo.net/tutorials/SDL/31_scrolling_backgrounds/index.php
class Dot{
    public:

        Dot(Image const& img);
        ~Dot();

        //Moves the dot
        void move(int direction);

        //Shows the dot on the screen
        void render(const Area &dest);

    private:
        //The X and Y offsets of the dot
        const Image& img;
        int x, y;

        //The velocity of the dot
        int mVelX, mVelY;
};


#endif