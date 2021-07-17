#ifndef _SOLDIER_H_
#define _SOLDIER_H_
#include "Directions.h"
#include "Animation.h"
#include "DynamicObject.h"

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
        Soldier(const Soldier &other) = delete;
        Soldier& operator=(const Soldier &other) = delete;
        Soldier& operator=(Soldier &&other) = delete;

    public:
        Soldier(std::string imgPath, Window &window);
        // Soldier(Soldier &&other);
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
};

#endif // _SOLDIER_H_
