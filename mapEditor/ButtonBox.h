#ifndef BUTTON_BOX_H
#define BUTTON_BOX_H

#include "Button.h"

class ButtonBox: public Button{
    private:
        ButtonBox(const ButtonBox &other) = delete;
        ButtonBox& operator=(const ButtonBox &other) = delete;
        ButtonBox& operator=(ButtonBox &&other) = delete;

    Window& window;

    public:
        ButtonBox(Window &window, EditorConfig& editor);
        ~ButtonBox();

        virtual void render();
        virtual bool clicked(std::vector<Tile*>& options,std::vector<Tile*>& obstaclesOptionTiles,
                             std::vector<Tile*>& soldierOptionsTiles, const Image& image, 
                             const Image& obsImage,const std::string& sizeName,
                             const Image& tImage,const Image& ctImage) override;
};

#endif