#ifndef __SOLDIER_H__
#define __SOLDIER_H__

#include "Animation.h"
#include "Image.h"
#include "Area.h"
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define UP_RIGHT 4
#define DOWN_RIGHT 5
#define UP_LEFT 6
#define DOWN_LEFT 7


class Soldier {
public:
    Soldier(Image &image);
    ~Soldier();
    void update(float dt);
    void render();
    void moveRigth();
    void moveLeft();
    void moveUp();
    void moveDown();
    void stopMoving();
    void clear();

private:
    Animation an;
    int direction;
    bool facingLeft;
    bool moving;
    int x;
    int y;
    int height;
    int width;
    int angle;
};

#endif // __SOLDIER_H__