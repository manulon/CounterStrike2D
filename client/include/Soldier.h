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
        float x;
        float y;
        int width;
        int height;
        int angle;
        short weaponId;
        short life;
        //Window& window;
        Weapon currentWeapon;

        Soldier(const Soldier &other) = delete;
        Soldier& operator=(const Soldier &other) = delete;

        void renderWeapon(int x, int y);
        void renderActualLife();
        void renderFullLife();
        void renderLife();

    public:
        Soldier(std::string imgPath, Window &window);
        Soldier(Soldier &&other); 
        Soldier& operator=(Soldier &&other);
        ~Soldier();
        void update(float dt);
        void render();
        virtual void render(int x, int y) override;
        void stopMoving();
        void move();
        float getX();
        float getY();
        int getAngle();
        void setAngle(int angle);
        void updateInfo(float x , float y, short weaponId);
        void updateInfoo(float x , float y, short weaponId);
        void setAsTerrorist();
        void setCurrentWeapon();
        void setLife(short life);
};

#endif // _SOLDIER_H_
