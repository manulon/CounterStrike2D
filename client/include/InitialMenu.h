#ifndef _INITIAL_MENU_H_
#define _INITIAL_MENU_H_

#include "Window.h"
#include "GameOption.h"
#include "InitialMenuEventHandler.h"

#include <vector>

class InitialMenu{
    private:
        InitialMenu(const InitialMenu& other) = delete;
        InitialMenu& operator=(const InitialMenu& other) = delete;

        Window window;
        std::vector<GameOption*> buttons;
        InitialMenuEventHandler handler;

    public:
        InitialMenu();
        ~InitialMenu();

        void close();
        void setInitialButtons();
        void render();
        void clear();
        bool handleEvents();
        std::string& getMapPath();
        std::string& getTilesPath();
        bool startGame();
};

#endif
