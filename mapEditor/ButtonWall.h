#ifndef BUTTON_WALL_H
#define BUTTON_WALL_H

#include "Button.h"

class ButtonWall: public Button{
    private:
        ButtonWall(const ButtonWall &other) = delete;
        ButtonWall& operator=(const ButtonWall &other) = delete;
        ButtonWall& operator=(ButtonWall &&other) = delete;

    Window& window;

    public:
        ButtonWall(Window &window,EditorConfig& editor);
        ~ButtonWall();

        virtual void render();
        virtual bool clicked(std::vector<Tile*>& options,std::vector<Tile*>& obstaclesOptionTiles,
                            const Image& image,const Image& obsImage,const std::string& sizeName);
};

#endif