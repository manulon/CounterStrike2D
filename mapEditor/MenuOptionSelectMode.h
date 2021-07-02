#ifndef _MENU_OPTION_SELECT_MODE_
#define _MENU_OPTION_SELECT_MODE_

#include "MenuOption.h"
#include "MapOptionAztec.h"
#include "MapOptionInferno.h"
#include "MapOptionDust.h"
#include <vector>

class MenuOptionSelectMode : public MenuOption{
    private:
        MenuOptionSelectMode(const MenuOptionSelectMode &other) = delete;
        MenuOptionSelectMode& operator=(const MenuOptionSelectMode &other) = delete;
        MenuOptionSelectMode& operator=(MenuOptionSelectMode &&other) = delete;

    Window& window;

    public:
        MenuOptionSelectMode(const char *fontPath, int ptsize,
		           const char *textToRender,Window &window);
        ~MenuOptionSelectMode();

        virtual bool clicked(std::vector<MenuOption*>& options) override;
        virtual void render() override;
        virtual const char* getPathToImage() override;
        virtual const char* getMapName() override;
};

#endif