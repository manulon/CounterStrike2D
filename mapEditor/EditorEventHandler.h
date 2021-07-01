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
      const Image& image;

      bool mouseInTile(int x, int y,Tile* tile);
      void renderTiles(std::vector<Tile*>& tiles,std::vector<Tile*>& optionTiles);
      void buildTileClips();
      bool mouseInGrid(int mousePositionX,int mousePositionY);
      void checkPosition(Tile* tile);
      void mouseMotionHandler(SDL_Event& event, std::vector<Tile*>& tiles);
      void mouseMotionUp(SDL_Event& event, std::vector<Tile*>& tiles);
      void mouseMotionDown
      (SDL_Event& event, std::vector<Tile*>& tiles,std::vector<Tile*>& optionTiles,
      std::vector<Button*>& buttons);

   public:
      EditorEventHandler(Window &window,const Image& image);
      ~EditorEventHandler();

      bool handleEvents
      (std::vector<Tile*>& tiles, std::vector<Tile*>& optionTiles,
      std::vector<Button*>& buttons);
};

#endif  // _EDITOR_EVENT_HANDLER_H_
