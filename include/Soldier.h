#ifndef _SOLDIER_H_
#define _SOLDIER_H_

#include "Animation.h"

enum {
    UP, 
    DOWN, 
    LEFT, 
    RIGHT, 
    UP_RIGHT, 
    DOWN_RIGHT, 
    UP_LEFT, 
    DOWN_LEFT
};

class Soldier : public Animation {        
    private:
        int direction;
        bool facingLeft;
        bool moving;
        int x;
        int y;
        int width;
        int height;
        int angle;

        Soldier(const Soldier &other) = delete;
        Soldier& operator=(const Soldier &other) = delete;
        Soldier& operator=(Soldier &&other) = delete;

    public:
        Soldier(const Image &image);
        Soldier(Soldier &&other);
        ~Soldier();
        void update(float dt);
        void render();
        void stopMoving();
        void stopLeft();
        void stopRight();
        void stopUp();    
        void stopDown();
        void move(char dir);
};

#endif // _SOLDIER_H_
