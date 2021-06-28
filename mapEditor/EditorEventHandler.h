#ifndef _EDITOR_EVENT_HANDLER_H_
#define _EDITOR_EVENT_HANDLER_H_

#include "Area.h"
#include "Window.h"
#include "SDL2/SDL.h"
#include "Tile.h"
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

      bool mouseInTile(int x, int y,Tile* tile);

   public:
      EditorEventHandler(Window &window);
      ~EditorEventHandler();

      bool handleEvents(std::vector<Tile*> tiles);
};

#endif  // _EDITOR_EVENT_HANDLER_H_
