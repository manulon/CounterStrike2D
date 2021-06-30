#ifndef _MENU_OPTION_EXIT_MODE_
#define _MENU_OPTION_EXIT_MODE_

#include "MenuOption.h"

class MenuOptionExitMode : public MenuOption{
    private:
        MenuOptionExitMode(const MenuOptionExitMode &other) = delete;
        MenuOptionExitMode& operator=(const MenuOptionExitMode &other) = delete;
        MenuOptionExitMode& operator=(MenuOptionExitMode &&other) = delete;

    public:
        MenuOptionExitMode(const char *fontPath, int ptsize,
		           const char *textToRender, 
		           SDL_Color color, Window &window);
        ~MenuOptionExitMode();

        virtual bool clicked() override;
};

#endif