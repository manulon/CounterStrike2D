#ifndef BUTTON_MISC_H
#define BUTTON_MISC_H

#include "Button.h"

class ButtonMisc: public Button{
    private:
        ButtonMisc(const ButtonMisc &other) = delete;
        ButtonMisc& operator=(const ButtonMisc &other) = delete;
        ButtonMisc& operator=(ButtonMisc &&other) = delete;

    Window& window;

    public:
        ButtonMisc(Window &window,EditorConfig& editor);
        ~ButtonMisc();

        virtual void render();
        virtual bool clicked(std::vector<Tile*>& options,std::vector<Tile*>& obstaclesOptionTiles,
                             std::vector<Tile*>& soldierOptionsTiles, const Image& image, 
                             const Image& obsImage,const std::string& sizeName,
                             const Image& tImage,const Image& ctImage, const Image& weapon) override;
};

#endif