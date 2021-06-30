#ifndef _MENU_OPTION_H
#define _MENU_OPTION_H

#include "SdlColor.h"
#include "Window.h"
#include "Text.h"
#include "Area.h"

class MenuOption{
    private:
        MenuOption(const MenuOption &other) = delete;
        MenuOption& operator=(const MenuOption &other) = delete;
        MenuOption& operator=(MenuOption &&other) = delete;

    protected:
        Text optionText;

    public:
        MenuOption(const char *fontPath, int ptsize,
		           const char *textToRender, 
		           SDL_Color color, Window &window);
        virtual ~MenuOption();

        void render(const Area &dest);
        bool mouseInText(int x, int y);
        virtual void clicked() = 0;
};

#endif