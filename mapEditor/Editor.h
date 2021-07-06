#ifndef _EDITOR_H
#define _EDITOR_H

#include "Window.h"
#include "Image.h"
#include "Area.h"
#include "EditorEventHandler.h"
#include "Tile.h"
#include "ButtonBox.h"
#include "ButtonFloor.h"
#include "ButtonMisc.h"
#include "ButtonObstacles.h"
#include "ButtonWeaponCharacter.h"
#include "EditorConfig.h"
#include <vector>

#define SMALL_WIDTH 800
#define BIG_WIDTH   1056
#define HUGE_WIDTH  1312


class Editor{
    private:
        Editor(const Editor &other) = delete;
        Editor& operator=(const Editor &other) = delete;
        Editor& operator=(Editor &&other) = delete;
    
        Window window;
        Image grid;
        Image image;
        Image selectedTile;
        Image obsImage;
        std::vector<Tile*> tiles;
        std::vector<Tile*> optionTiles;
        std::vector<Tile*> obstaclesOptionTiles;
        std::vector<Button*> tileOptionButton;
        EditorEventHandler eventHandler;
        EditorConfig editor;
        std::string sizeName;
        

   public:
        Editor(const char* path, const char* mapName, 
               std::pair<int,int>& size);
        ~Editor();

        void showGrid();
        bool handleEvents();
        void fillTileOptionList();
        void showMenu();
        void startEditor();
        void setSizeName();
        void clearWindow();
        void render();
};

#endif //_EDITOR_H