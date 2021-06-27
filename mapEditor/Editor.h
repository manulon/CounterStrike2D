#ifndef _EDITOR_H
#define _EDITOR_H

#include "Image.h"
#include "EditorEventHandler.h"

class Editor{
    private:
        Editor(const Editor &other) = delete;
        Editor& operator=(const Editor &other) = delete;
        Editor& operator=(Editor &&other) = delete;
    
        EditorEventHandler eventHandler;
        Window& window;
        const Image grid;

   public:
        Editor(Window& window);
        ~Editor();

        void showGrid();
        bool handleEvents();
        void renderImageTest();
};

#endif //_EDITOR_H