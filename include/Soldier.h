#ifndef __SOLDIER_H__
#define __SOLDIER_H__

#include "Animation.h"
#include "Image.h"
#include "Area.h"
#define UP 'u'
#define DOWN 'd'
#define LEFT 'l'
#define RIGHT 'r'
#define UP_RIGHT 'U'
#define DOWN_RIGHT 'D'
#define UP_LEFT 'L'
#define DOWN_LEFT 'P'


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
    char direction;
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