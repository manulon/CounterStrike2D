#ifndef _EDITOR_EVENT_HANDLER_H_
#define _EDITOR_EVENT_HANDLER_H_

#include "Area.h"
#include "SDL2/SDL.h"

class EditorEventHandler {
   private:
      EditorEventHandler(const EditorEventHandler &other) = delete;
      EditorEventHandler& operator=(const EditorEventHandler &other) = delete;
      EditorEventHandler& operator=(EditorEventHandler &&other) = delete;
      
      bool leftMouseButtonDown;
      Area& area;
      SDL_Point& mousePos;
   
   public:
      EditorEventHandler(Area &area, SDL_Point& mousePos);
      EditorEventHandler(EditorEventHandler &&other);
      ~EditorEventHandler();

      static bool handleEvents();
};

#endif  // _EDITOR_EVENT_HANDLER_H_
