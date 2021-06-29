#ifndef _MENU_EDITOR_EVENT_HANDLER_H
#define _MENU_EDITOR_EVENT_HANDLER_H

#include "SDL2/SDL.h"

class MenuEditorEventHandler{
    private:
        MenuEditorEventHandler(const MenuEditorEventHandler &other) = delete;
        MenuEditorEventHandler& operator=(const MenuEditorEventHandler &other) = delete;
        MenuEditorEventHandler& operator=(MenuEditorEventHandler &&other) = delete;

        void mouseMotionHandler();
        void mouseMotionDown();
        void mouseMotionUp();

    public:
        MenuEditorEventHandler();
        ~MenuEditorEventHandler();

        bool handleEvents();
};

#endif