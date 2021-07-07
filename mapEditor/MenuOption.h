#ifndef _MENU_OPTION_H
#define _MENU_OPTION_H

#include "Window.h"
#include "yaml-cpp/yaml.h"
#include "Area.h"
#include "Image.h"
#include <vector>

class MenuOption{
    private:
        MenuOption(const MenuOption &other) = delete;
        MenuOption& operator=(const MenuOption &other) = delete;
        MenuOption& operator=(MenuOption &&other) = delete;
        
    protected:
        Image button;
        Area buttonArea;

    public:
        MenuOption(const char* pontPath, Window &window, int x, int y, int w, int h);
        virtual ~MenuOption();

        
        virtual bool mouseInButton(int x, int y) = 0;
        virtual bool clicked(std::vector<MenuOption*>& options) = 0;
        virtual void render() = 0;
        virtual const char* getPathToImage() = 0;
        virtual const char* getMapName() = 0;
        virtual void setPair(std::pair<int,int>& pair) = 0;
};

#endif