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
        std::vector<Tile*> optionTiles;
        EditorEventHandler eventHandler;

   public:
        Editor(Window& window, const char* path);
        ~Editor();

        void showGrid();
        bool handleEvents();
        void fillTileOptionList();
        void showMenu();
        void startEditor();
};

#endif //_EDITOR_H