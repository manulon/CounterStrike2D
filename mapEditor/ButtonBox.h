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
        ButtonBox(Window &window);
        ~ButtonBox();

        virtual void render();
        virtual bool clicked();
};

#endif