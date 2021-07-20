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
        int id;

        Soldier(const Soldier &other) = delete;
        Soldier& operator=(const Soldier &other) = delete;

        void renderActualLife();
        void renderFullLife();
        void renderLife();

    public:
        Soldier(std::string imgPath, Window &window);
        Soldier(std::string imgPath, Window &window, int id);
        Soldier(Soldier &&other); 
        Soldier& operator=(Soldier &&other);
        ~Soldier();
        void render();
        virtual void render(int x, int y) override;
        void stopMoving();
        void move();
        float getX();
        float getY();
        int getAngle();
        void setAngle(int angle);
        void updateInfo(float x , float y, short weaponId);
        void updateInfoo(float x , float y, short weaponId, short angle);
        void setAsTerrorist();
        void changeCurrentWeapon();
        void setLife(short life);
        void setId(short idd);
};

#endif // _SOLDIER_H_
