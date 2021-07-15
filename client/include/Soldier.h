#ifndef _SOLDIER_H_
#define _SOLDIER_H_

#include "Directions.h"
#include "Animation.h"
#include "DynamicObject.h"
#include "Weapon.h"

class Soldier : public Animation , public DynamicObject{        
    private:
        int direction;
        bool moving;
        // int x;
        // int y;
        int width;
        int height;
        int angle;
        short int life;
        Window& window;
        Weapon currentWeapon;

        Soldier(const Soldier &other) = delete;
        Soldier& operator=(const Soldier &other) = delete;
        Soldier& operator=(Soldier &&other) = delete;

        void renderWeapon(int x, int y);
        void renderLife();
        void namePathFactory();

    public:
        Soldier(std::string imgPath, Window &window);
        // Soldier(Soldier &&other);
        ~Soldier();
        void update(float dt);
        void render();
        virtual void render(int x, int y) override;
        void stopMoving();
        void move();
        int getX();
        int getY();
        int getAngle();
        void setAngle(int angle);
        void setCurrentWeapon();
};

#endif // _SOLDIER_H_
