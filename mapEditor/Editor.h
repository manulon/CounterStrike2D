#ifndef _EDITOR_H
#define _EDITOR_H

#include "Window.h"
#include "Image.h"
#include "Area.h"
#include "EditorEventHandler.h"

class Editor{
    private:
        Editor(const Editor &other) = delete;
        Editor& operator=(const Editor &other) = delete;
        Editor& operator=(Editor &&other) = delete;
    
        Window& window;
        const Image grid;
        const Image image;
        Area area;
        EditorEventHandler eventHandler;

   public:
        Editor(Window& window);
        ~Editor();

        void renderImageTest();
        void showGrid();
        bool handleEvents();
};

#endif //_EDITOR_H