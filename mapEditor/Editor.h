#ifndef _EDITOR_H
#define _EDITOR_H

#include "Window.h"
#include "Image.h"
#include "Area.h"
#include "EditorEventHandler.h"
#include "Tile.h"
#include <vector>

class Editor{
    private:
        Editor(const Editor &other) = delete;
        Editor& operator=(const Editor &other) = delete;
        Editor& operator=(Editor &&other) = delete;
    
        Window& window;
        const Image grid;
        const Image image;
        std::vector<Tile*> tiles;
        EditorEventHandler eventHandler;

   public:
        Editor(Window& window);
        ~Editor();

        void showGrid();
        bool handleEvents();
        void fillTileOptionList();
};

#endif //_EDITOR_H