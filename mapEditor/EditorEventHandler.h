#ifndef _EDITOR_EVENT_HANDLER_H_
#define _EDITOR_EVENT_HANDLER_H_

#include "Area.h"
#include "Window.h"
#include "SDL2/SDL.h"
#include <iostream>

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
      Area& area;

   public:
      EditorEventHandler(Area& area, Window &window);
      ~EditorEventHandler();

      bool handleEvents();
};

#endif  // _EDITOR_EVENT_HANDLER_H_
