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
        ButtonWeaponCharacter(Window &window,EditorConfig& editor);
        ~ButtonWeaponCharacter();

        virtual void render();
        virtual bool clicked(std::vector<Tile*>& options,std::vector<Tile*>& obstaclesOptionTiles,
                             std::vector<Tile*>& soldierOptionsTiles, const Image& image, 
                             const Image& obsImage,const std::string& sizeName,
                             const Image& tImage,const Image& ctImage) override;
};

#endif