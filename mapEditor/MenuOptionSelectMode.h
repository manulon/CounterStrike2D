#ifndef _MENU_OPTION_SELECT_MODE_
#define _MENU_OPTION_SELECT_MODE_

#include "MenuOption.h"

class MenuOptionSelectMode : public MenuOption{
    private:
        MenuOptionSelectMode(const MenuOptionSelectMode &other) = delete;
        MenuOptionSelectMode& operator=(const MenuOptionSelectMode &other) = delete;
        MenuOptionSelectMode& operator=(MenuOptionSelectMode &&other) = delete;

    public:
        MenuOptionSelectMode(const char *fontPath, int ptsize,
		           const char *textToRender, 
		           SDL_Color color, Window &window);
        ~MenuOptionSelectMode();

        virtual bool clicked() override;
};

#endif