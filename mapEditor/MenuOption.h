#ifndef _MENU_OPTION_H
#define _MENU_OPTION_H

#include "SdlColor.h"
#include "Window.h"
#include "Text.h"
#include "Area.h"
#include <vector>

class MenuOption{
    private:
        MenuOption(const MenuOption &other) = delete;
        MenuOption& operator=(const MenuOption &other) = delete;
        MenuOption& operator=(MenuOption &&other) = delete;

    SdlColor color;

    protected:
        Text optionText;

    public:
        MenuOption(const char *fontPath, int ptsize,
		           const char *textToRender,Window &window);
        virtual ~MenuOption();

        
        bool mouseInText(int x, int y);
        virtual bool clicked(std::vector<MenuOption*>& options) = 0;
        virtual void render() = 0;
        virtual const char* getPathToImage() = 0;
        virtual const char* getMapName() = 0;
        virtual void setPair(std::pair<int,int>& pair) = 0;
};

#endif