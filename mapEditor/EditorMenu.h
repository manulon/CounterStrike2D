#ifndef _EDITOR_MENU_H
#define _EDITOR_MENU_H

#include "Text.h"
#include "Window.h"
#include "Area.h"
#include "SdlColor.h"
#include "MenuEditorEventHandler.h"

class EditorMenu{
    private:
        SdlColor textColor;
        Window window;
        Text textSelectMode;
        Text textExit;
        MenuEditorEventHandler handler;
        std::vector<Text> options;

    EditorMenu(const EditorMenu &other) = delete;
    EditorMenu& operator=(const EditorMenu &other) = delete;
    EditorMenu& operator=(EditorMenu &&other) = delete;

    public:
        EditorMenu();
        ~EditorMenu();

        void render();
        void close();
        void clear();
        bool handleEvents();

};

#endif //_EDITOR_MENU_H