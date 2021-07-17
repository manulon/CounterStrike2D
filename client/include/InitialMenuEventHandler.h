#ifndef _INITIAL_MENU_EVENT_HANDLER_H_
#define _INITIAL_MENU_EVENT_HANDLER_H_

#include <vector>
#include "GameOption.h"

class InitialMenuEventHandler{
    private:
        InitialMenuEventHandler(const InitialMenuEventHandler &other) = delete;
        InitialMenuEventHandler& operator=(const InitialMenuEventHandler &other) = delete;
        InitialMenuEventHandler& operator=(InitialMenuEventHandler &&other) = delete;

        int mousePositionX;
        int mousePositionY;
        std::string mapPath;
        std::string tilesPath;

        bool mouseMotionHandler(SDL_Event& event,std::vector<GameOption*>& options);
        bool mouseMotionDown(SDL_Event& event,std::vector<GameOption*>& options);

    public:
        InitialMenuEventHandler();
        ~InitialMenuEventHandler();

        bool handleEvents(std::vector<GameOption*>& options);
        std::string& getMapPath();
        std::string& getTilesPath();
};

#endif