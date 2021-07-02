#ifndef _WEAPON_H_
#define _WEAPON_H_
#include "Image.h"
class Weapon{
    private:
        Weapon(const Weapon &other) = delete;
        Weapon& operator=(const Weapon &other) = delete;
        Weapon& operator=(Weapon &&other) = delete;
    public:
        Weapon(const Image &image);
        Weapon(Weapon &&other);
        Weapon(/* args */);
        ~Weapon();
};

#endif
