#include "EditorEventHandler.h"
#include "Image.h"

EditorEventHandler::EditorEventHandler(Window& window): 
leftMouseButtonDown(false),mousePositionX(0),mousePositionY(0),
windowWidth(window.getWidth()),windowHeight(window.getHeight()),tileNumber(-1){}

bool EditorEventHandler::handleEvents(std::vector<Tile*> tiles){
   SDL_Event event;
   int x_aux(0);
   int y_aux(0);
   
   for (int i=0; i<75; i++){
        tileClips[i].x = x_aux;
        tileClips[i].y = y_aux;
        tileClips[i].w = 32;
        tileClips[i].h = 32;

        x_aux += 32;

        if (x_aux==160){
        	x_aux=0;
        	y_aux+=32;
        }
    }

   while (SDL_PollEvent(&event)){
      switch (event.type) {
         case SDL_MOUSEMOTION:{
            mousePositionX = event.motion.x;
            mousePositionY = event.motion.y;
            if (leftMouseButtonDown && tileNumber != -1){
               tiles[tileNumber]->setX(mousePositionX);
               tiles[tileNumber]->setY(mousePositionY);
            }
         }
         break;

         case SDL_MOUSEBUTTONDOWN: {
            if (!leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT){ 
               leftMouseButtonDown = true;
               for (auto tile : tiles){
                  tileNumber++;
                  if (mouseInTile(mousePositionX,mousePositionY,tile)){
                     tiles[tileNumber]->setX(tile->getX());
                     tiles[tileNumber]->setY(tile->getY());
                     break;
                  } 
               }
            }
         }
         break;

         case SDL_MOUSEBUTTONUP:{
            leftMouseButtonDown = false;

            for (auto tile : tiles){
               if (mouseInTile(mousePositionX,mousePositionY,tile)){
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
                     auxX = windowWidth-32;            // 32 CONSTANTE
                     
                  if ( auxY >= windowHeight-128 )
                     auxY = windowHeight-128-24;       // 24 Y 128 CONSTANTE    
                     
                  tiles[tileNumber]->setX(auxX);
                  tiles[tileNumber]->setY(auxY);
               }
            }
            
            tileNumber = -1;  
         }
         break;

         case SDL_QUIT:
            std::cout << "Quit :(" << std::endl;
            return false;
        }
   }

   for (auto& tile: tiles){     
      int xOffset(tile->getX());
      int yOffset(tile->getY());
      int type(tile->getType());
      tile->setMBox(tileClips[type-1]);

      Area finalArea(xOffset,yOffset, 
                       tileClips[type-1].w, tileClips[type-1].h);
      tile->render(finalArea);
   }

   return true;
}

bool EditorEventHandler::mouseInTile(int x, int y, Tile* tile){
   return tile->mouseInTile(x,y);
}

EditorEventHandler::~EditorEventHandler(){}
