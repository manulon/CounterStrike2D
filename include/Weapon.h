#ifndef _WEAPON_H_
#define _WEAPON_H_
#include "Image.h"
#include "DynamicObject.h"
class Weapon : public DynamicObject{
    private:
        const Image image; 
        int x, y;
        int width, height;
        Weapon(const Weapon &other) = delete;
        Weapon& operator=(const Weapon &other) = delete;
        Weapon& operator=(Weapon &&other) = delete;
    public:
        Weapon(std::string imgPath,Window &window,int width,int height);
        Weapon(Weapon &&other);
        virtual void render(int x, int y) override;
        // void setPos(int xx, int yy);
        ~Weapon();
};

#endif