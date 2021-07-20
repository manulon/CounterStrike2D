#ifndef _EDITOR_EVENT_HANDLER_H_
#define _EDITOR_EVENT_HANDLER_H_

#include "Area.h"
#include "Window.h"
#include "SDL2/SDL.h"
#include "Tile.h"
#include "Image.h"
#include "Button.h"
#include <iostream>
#include <vector>

#define PPM 32

class EditorEventHandler {
   private:
      EditorEventHandler(const EditorEventHandler &other) = delete;
      EditorEventHandler& operator=(const EditorEventHandler &other) = delete;
      EditorEventHandler& operator=(EditorEventHandler &&other) = delete;
      
      bool leftMouseButtonDown;
      int mousePositionX;
      int mousePositionY;
      int windowWidth;
      int windowHeight;
      int tileNumber;
      int actualType;
      int selectedZoneX;
      int selectedZoneY;
      SDL_Rect tileClips[ 75 ];
      Image& image;
      Image& obsImage;
      Image tImage;
      Image ctImage;
      Image weaponImage;
      std::string actualImage;
      Window& window;
      std::map<std::pair<int,int>,int>& finalMapTiles;
      std::map<std::pair<int,int>,int> finalMapObstacles;
      std::map<std::pair<int,int>,int> terroristMap;
      std::map<std::pair<int,int>,int> counterTerroristMap;
      std::map<std::pair<int,int>,int> weaponMap;
      const char* mapName;
      int tileBoxHeight;
      int tileWidth;
      int tileHeight;

      bool mouseInTile(int x, int y,Tile* tile);
      void renderTiles(std::vector<Tile*>& tiles,std::vector<Tile*>& optionTiles,
                       std::vector<Tile*>& obstaclesOptionTiles,
                       std::vector<Tile*>& soldierOptionTiles);
      void buildTileClips();
      bool mouseInGrid(int mousePositionX,int mousePositionY);
      void putTileInCorrectPosition(Tile* tile);
      void mouseMotionHandler(SDL_Event& event, std::vector<Tile*>& tiles);
      void mouseMotionUp(SDL_Event& event, std::vector<Tile*>& tiles);
      void mouseMotionDown
      (SDL_Event& event, std::vector<Tile*>& tiles,std::vector<Tile*>& optionTiles,
      std::vector<Tile*>& obstaclesOptionTiles,std::vector<Button*>& buttons, 
      std::vector<Tile*>& soldierOptionTiles, const std::string& sizeName);
      Image& getActualImage();
      void changeActualImage(const std::string& newImage);

   public:
      EditorEventHandler(Window &window, Image& image, Image& obsImage, const char* mapName, 
                         std::map<std::pair<int,int>,int>& finalMapTiles);
      ~EditorEventHandler();

      bool handleEvents
      (std::vector<Tile*>& tiles, std::vector<Tile*>& optionTiles,
      std::vector<Tile*>& obstaclesOptionTiles,std::vector<Button*>& buttons, 
      std::vector<Tile*>& soldierOptionTiles, const std::string& sizeName);
};

#endif  // _EDITOR_EVENT_HANDLER_H_
