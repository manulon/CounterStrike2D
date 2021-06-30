#ifndef _EDITOR_MENU_H
#define _EDITOR_MENU_H

#include "Text.h"
#include "Window.h"
#include "Area.h"
#include "MenuEditorEventHandler.h"
#include "MenuOption.h"
#include "MenuOptionSelectMode.h"
#include "MenuOptionExitMode.h"

class EditorMenu{
    private:
        Window window;
        MenuOptionSelectMode textSelectMode;
        MenuOptionExitMode textExit;
        MenuEditorEventHandler handler;
        std::vector<MenuOption*> options;
        bool startEditor;

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
        bool runEditor();
        const char* getPath();

};

#endif //_EDITOR_MENU_H