#ifndef _SIZE_SELECTOR_MENU_H_
#define _SIZE_SELECTOR_MENU_H_

#include "MenuOption.h"
#include "SizeOptionSmall.h"
#include "SizeOptionBig.h"
#include "SizeOptionHuge.h"
#include "SdlColor.h"
#include "Window.h"
#include "Text.h"
#include <vector>

class SizeSelectorMenu{
    private:
        SizeSelectorMenu(const SizeSelectorMenu &other) = delete;
        SizeSelectorMenu& operator=(const SizeSelectorMenu &other) = delete;
        SizeSelectorMenu& operator=(SizeSelectorMenu &&other) = delete;

        void setSizeOptions(Window& window);
        bool mouseMotionUp(SDL_Event& event);
        bool mouseMotionDown(SDL_Event& event);
        bool mouseMotionHandler(SDL_Event& event);
        bool handleEvents();

        SdlColor color;
        int selectedWidth;
        int selectedHeight;
        std::pair<int,int> pair;
        int mousePositionX;
        int mousePositionY;
        std::vector<MenuOption*> sizeOptions;
        
    
    public:
        SizeSelectorMenu();
        ~SizeSelectorMenu();

        void run();
        std::pair<int,int>& getPair();
};

#endif