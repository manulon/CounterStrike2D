#ifndef _MENU_EDITOR_EVENT_HANDLER_H
#define _MENU_EDITOR_EVENT_HANDLER_H

#include "SDL2/SDL.h"
#include "Text.h"
#include <vector>

class MenuEditorEventHandler{
    private:
        MenuEditorEventHandler(const MenuEditorEventHandler &other) = delete;
        MenuEditorEventHandler& operator=(const MenuEditorEventHandler &other) = delete;
        MenuEditorEventHandler& operator=(MenuEditorEventHandler &&other) = delete;

        int mousePositionX;
        int mousePositionY;

        void mouseMotionHandler(SDL_Event& event,std::vector<Text*>& options);
        void mouseMotionDown(SDL_Event& event);
        void mouseMotionUp(SDL_Event& event);

    public:
        MenuEditorEventHandler();
        ~MenuEditorEventHandler();

        bool handleEvents(std::vector<Text*>& options);
};

#endif