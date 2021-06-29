#ifndef _EDITOR_EVENT_HANDLER_H_
#define _EDITOR_EVENT_HANDLER_H_

#include "Area.h"
#include "Window.h"
#include "SDL2/SDL.h"
#include "Tile.h"
#include "Image.h"
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
      SDL_Rect tileClips[ 75 ];
      const Image& image;

      bool mouseInTile(int x, int y,Tile* tile);
      void mouseMotionDown
      (SDL_Event& event, std::vector<Tile*>& tiles,std::vector<Tile*>& optionTiles);
      void mouseMotionHandler(SDL_Event& event, std::vector<Tile*>& tiles);
      void mouseMotionUp(SDL_Event& event, std::vector<Tile*>& tiles);
      void renderTiles(std::vector<Tile*>& tiles,std::vector<Tile*>& optionTiles);
      void buildTileClips();

   public:
      EditorEventHandler(Window &window,const Image& image);
      ~EditorEventHandler();

      bool handleEvents
      (std::vector<Tile*>& tiles, std::vector<Tile*>& optionTiles);
};

#endif  // _EDITOR_EVENT_HANDLER_H_
