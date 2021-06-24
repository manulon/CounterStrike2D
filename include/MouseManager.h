#ifndef _MOUSEMANAGER_H_
#define _MOUSEMANAGER_H_
#include <SDL2/SDL.h>
#include <math.h>
#define PI 3.14159265

class MouseManager {
    private:
        int x;
        int y;
    public:
        int getPositionX();
        int getPositionY();
        int getAngle();
};

#endif