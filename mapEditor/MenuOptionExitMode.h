#ifndef _MENU_OPTION_EXIT_MODE_
#define _MENU_OPTION_EXIT_MODE_

#include "MenuOption.h"
#include <vector>

class MenuOptionExitMode : public MenuOption{
    private:
        MenuOptionExitMode(const MenuOptionExitMode &other) = delete;
        MenuOptionExitMode& operator=(const MenuOptionExitMode &other) = delete;
        MenuOptionExitMode& operator=(MenuOptionExitMode &&other) = delete;

    public:
        MenuOptionExitMode(const char *fontPath, int ptsize,
		           const char *textToRender,Window &window);
        ~MenuOptionExitMode();

        virtual bool mouseInButton(int x, int y);
        virtual bool clicked(std::vector<MenuOption*>& options) override;
        virtual void render() override;
        virtual const char* getPathToImage() override;
        virtual const char* getMapName() override;

        virtual void setPair(std::pair<int,int>& pair) override;
};

#endif