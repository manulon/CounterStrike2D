#ifndef __SOLDIER_H__
#define __SOLDIER_H__

#include "Animation.h"
#include "Image.h"
#include "Area.h"

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
    bool facingLeft;
    bool facingRight;
    bool facingUp;
    bool moving;
    int x;
    int y;
    int height;
    int width;
    int angle;
};

#endif // __SOLDIER_H__