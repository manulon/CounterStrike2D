#ifndef _MOUSEMANAGER_H_
#define _MOUSEMANAGER_H_
#include <SDL2/SDL.h>
#include <math.h>
#define PI 3.14159265

class MouseManager {
    private:
        int x;
        int y;
        int windowWidth, windowHeight;
    public:
        MouseManager(int windowWidth, int windowHeight);
        int getPositionX();
        int getPositionY();
        int getAngle();
        void update();
};

#endif