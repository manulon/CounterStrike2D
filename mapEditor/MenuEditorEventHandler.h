#ifndef _MENU_EDITOR_EVENT_HANDLER_H
#define _MENU_EDITOR_EVENT_HANDLER_H

#include "SDL2/SDL.h"
#include "Text.h"
#include "MenuOption.h"
#include <vector>
#include <string>


class MenuEditorEventHandler{
    private:
        MenuEditorEventHandler(const MenuEditorEventHandler &other) = delete;
        MenuEditorEventHandler& operator=(const MenuEditorEventHandler &other) = delete;
        MenuEditorEventHandler& operator=(MenuEditorEventHandler &&other) = delete;

        int mousePositionX;
        int mousePositionY;
        std::string path;
        std::string mapName;

        bool mouseMotionHandler(SDL_Event& event,std::vector<MenuOption*>& options);
        bool mouseMotionDown(SDL_Event& event,std::vector<MenuOption*>& options);
        bool mouseMotionUp(SDL_Event& event);

    public:
        MenuEditorEventHandler();
        ~MenuEditorEventHandler();

        bool handleEvents(std::vector<MenuOption*>& options);
        std::string& getPath();
        std::string& getMapName();
};

#endif