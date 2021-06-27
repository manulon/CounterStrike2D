#ifndef _EDITOR_H
#define _EDITOR_H

#include "Window.h"
#include "Image.h"
#include "Area.h"

class Editor{
    private:
        Editor(const Editor &other) = delete;
        Editor& operator=(const Editor &other) = delete;
        Editor& operator=(Editor &&other) = delete;
    
        Window& window;
        const Image grid;

   public:
        Editor(Window& window);
        ~Editor();

        void showGrid();
};

#endif //_EDITOR_H