#ifndef _EDITOR_MENU_H
#define _EDITOR_MENU_H

#include "Text.h"
#include "Window.h"
#include "Area.h"
#include "SdlColor.h"

class EditorMenu{
    private:
        SdlColor textColor;
        Window window;
        Text textSelectMode;
        Text textExit;

    EditorMenu(const EditorMenu &other) = delete;
    EditorMenu& operator=(const EditorMenu &other) = delete;
    EditorMenu& operator=(EditorMenu &&other) = delete;

    public:
        EditorMenu();
        ~EditorMenu();

        void render();
        void close();

};

#endif //_EDITOR_MENU_H