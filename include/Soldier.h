#ifndef _SOLDIER_H_
#define _SOLDIER_H_
#include "Directions.h"
#include "Animation.h"

class Soldier : public Animation {        
    private:
        int direction;
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
        int getX();
        int getY();
        int getAngle();
        void setAngle(int angle);
};

#endif // _SOLDIER_H_
