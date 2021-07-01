#ifndef BUTTON_WEAPON_CHARACTER_H
#define BUTTON_WEAPON_CHARACTER_H

#include "Button.h"

class ButtonWeaponCharacter: public Button{
    private:
        ButtonWeaponCharacter(const ButtonWeaponCharacter &other) = delete;
        ButtonWeaponCharacter& operator=(const ButtonWeaponCharacter &other) = delete;
        ButtonWeaponCharacter& operator=(ButtonWeaponCharacter &&other) = delete;

    Window& window;

    public:
        ButtonWeaponCharacter(Window &window);
        ~ButtonWeaponCharacter();

        virtual void render();
        virtual bool clicked();
};

#endif