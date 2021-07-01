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
        ButtonMisc(Window &window);
        ~ButtonMisc();

        virtual void render();
        virtual bool clicked();
};

#endif