#include "EditorEventHandler.h"
#include "Image.h"

EditorEventHandler::EditorEventHandler(Window& window): 
leftMouseButtonDown(false),mousePositionX(0),mousePositionY(0),
windowWidth(window.getWidth()),windowHeight(window.getHeight()),
area(0,0,32,32),image("assets/gfx/tiles/default_dust.png", window){}

bool EditorEventHandler::handleEvents(){
   SDL_Event event;
    while (SDL_PollEvent(&event)){
      switch (event.type) {
         case SDL_MOUSEMOTION:{
            mousePositionX = event.motion.x;
            mousePositionY = event.motion.y;
            if (leftMouseButtonDown){
               area.setX(mousePositionX);
               area.setY(mousePositionY);
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

            int auxX( mousePositionX%32 ); // TAMBIEN CONSTANTE, EL TILE WIDTH
            int auxY( mousePositionY%32 ); // TAMBIEN CONSTANTE, EL TILE HEIGHT

            if ( auxX > 16 && auxY < 16 ){
               auxX = 32*((int)( (mousePositionX/32)+1 ));
               auxY = 32*((int)( (mousePositionY/32) ));
            }else if ( auxX > 16 && auxY > 16 ){
               auxX = 32*((int)( (mousePositionX/32)+1 ));
               auxY = 32*((int)(mousePositionY/32)+1);
            }else if ( auxX < 16 && auxY > 16 ){
               auxX = 32*((int)(mousePositionX/32));
               auxY = 32*((int)((mousePositionY/32)+1));
            }else{
               auxX = 32*((int)(mousePositionX/32));
               auxY = 32*((int)(mousePositionY/32));
            }

            if ( auxX >= windowWidth - 32 )
               auxX = windowWidth-32;           // 32 CONSTANTE
            
            if ( auxY >= windowHeight-128 )
               auxY = windowHeight-128-24;       // 24 Y 128 CONSTANTE    
            
            area.setX(auxX);
            area.setY(auxY);
         }
         break;

         case SDL_QUIT:
            std::cout << "Quit :(" << std::endl;
            return false;
        }
    }
    return true;
}

void EditorEventHandler:: renderImageTest(){
   image.render(area);
}

EditorEventHandler::~EditorEventHandler(){}
