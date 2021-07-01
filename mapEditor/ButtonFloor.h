#ifndef BUTTON_FLOOR_H
#define BUTTON_FLOOR_H

#include "Button.h"

class ButtonFloor: public Button{
    private:
        ButtonFloor(const ButtonFloor &other) = delete;
        ButtonFloor& operator=(const ButtonFloor &other) = delete;
        ButtonFloor& operator=(ButtonFloor &&other) = delete;

    Window& window;

    public:
        ButtonFloor(Window &window);
        ~ButtonFloor();

        virtual void render();
        virtual bool clicked(std::vector<Button*> buttons);
};

#endif