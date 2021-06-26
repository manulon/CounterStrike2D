#include "EditorEventHandler.h"

EditorEventHandler:: EditorEventHandler(Area &area, SDL_Point& mousePos): 
leftMouseButtonDown(false),area(area),mousePos(mousePos){}

EditorEventHandler:: EditorEventHandler(EditorEventHandler &&other){

}

static bool handleEvents(){
   SDL_Event event;
    while (SDL_PollEvent(&event)){
      switch (event.type) {
         case SDL_MOUSEMOTION:{
            mousePos = { event.motion.x, event.motion.y };
            if (leftMouseButtonDown){
               area.setX(mousePos.x);
               area.setY(mousePos.y);
            }
         }
         break;

         case SDL_MOUSEBUTTONDOWN: {
            if (!leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT)
            leftMouseButtonDown = true;
         }
         break;

         case SDL_MOUSEBUTTONUP:{
            leftMouseButtonDown = false;
         }
         break;

         case SDL_QUIT:
            std::cout << "Quit :(" << std::endl;
            return false;
        }
    }
    return true;
}

EditorEventHandler:: ~EditorEventHandler(){}
