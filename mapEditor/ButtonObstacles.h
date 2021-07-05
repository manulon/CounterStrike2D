#ifndef BUTTON_OBSTACLES_H
#define BUTTON_OBSTACLES_H

#include "Button.h"

class ButtonObstacles: public Button{
    private:
        ButtonObstacles(const ButtonObstacles &other) = delete;
        ButtonObstacles& operator=(const ButtonObstacles &other) = delete;
        ButtonObstacles& operator=(ButtonObstacles &&other) = delete;

    Window& window;

    public:
        ButtonObstacles(Window &window,EditorConfig& editor);
        ~ButtonObstacles();

        virtual void render();
        virtual bool clicked(std::vector<Tile*>& options,std::vector<Tile*>& obstaclesOptionTiles,
                            const Image& image,const Image& obsImage,const std::string& sizeName);
};

#endif