#include "EditorEventHandler.h"
#include "Image.h"
#include "MapEditor.h"

EditorEventHandler::EditorEventHandler(Window& window,const Image& image): 
leftMouseButtonDown(false),mousePositionX(0),mousePositionY(0),
windowWidth(window.getWidth()),windowHeight(window.getHeight()),tileNumber(-1),
image(image){}

bool EditorEventHandler::handleEvents
(std::vector<Tile*>& tiles, std::vector<Tile*>& optionTiles){
   SDL_Event event;

   buildTileClips();

   while (SDL_PollEvent(&event)){
      switch (event.type) {
         case SDL_MOUSEMOTION:
            mouseMotionHandler(event, tiles);
            break;

         case SDL_MOUSEBUTTONDOWN:
            mouseMotionDown(event, tiles, optionTiles);
            break;

         case SDL_MOUSEBUTTONUP:
            mouseMotionUp(event, tiles);
            break;

         case SDL_QUIT:
            MapEditor map;
            map.createMap("MapaDePruebaEditor","dust");
            for (auto& tile : tiles){
               map.addField(tile->getX(),tile->getY(),tile->getType());
            }
            map.generateMap();
            return false;
        }
   }

   renderTiles(tiles,optionTiles);

   return true;
}

bool EditorEventHandler::mouseInTile(int x, int y, Tile* tile){
   return tile->mouseInTile(x,y);
}

void EditorEventHandler::mouseMotionHandler
(SDL_Event& event,std::vector<Tile*>& tiles){
   mousePositionX = event.motion.x;
   mousePositionY = event.motion.y;
   if (leftMouseButtonDown && tileNumber != -1){
      tiles[tileNumber]->setX(mousePositionX);
      tiles[tileNumber]->setY(mousePositionY);
   }
}

void EditorEventHandler::mouseMotionDown
(SDL_Event& event,std::vector<Tile*>& tiles,std::vector<Tile*>& optionTiles){
   if (!leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT){ 
      leftMouseButtonDown = true;
      for (auto& tile : optionTiles){
         if (mouseInTile(mousePositionX,mousePositionY,tile)){
            tiles.push_back(new Tile(tile->getType(),
                           tile->getInitialPositionX(),
                           tile->getInitialPositionY(),
                           image));
            tileNumber=(tiles.size()-1);                           
            break;
         } 
      }

      for (size_t i=0; i<tiles.size(); i++){
         if (mouseInTile(mousePositionX,mousePositionY,tiles[i])){
            tileNumber=(int)i;
            break;
         }
         i++;
      }   
   }
}

void EditorEventHandler::mouseMotionUp
(SDL_Event& event, std::vector<Tile*>& tiles){
   leftMouseButtonDown = false;

   for (auto& tile : tiles){
      if (tile->tileOutOfPosition()){
         int auxX( mousePositionX%32 ); // TAMBIEN CONSTANTE, EL TILE WIDTH
         int auxY( mousePositionY%32 ); // TAMBIEN CONSTANTE, EL TILE HEIGHT
         
         if ( auxX > 16 && auxY < 16 ){
            auxX = ((int)( (mousePositionX/32)+1 ));
            auxY = ((int)( (mousePositionY/32) ));
         }else if ( auxX > 16 && auxY > 16 ){
            auxX = ((int)( (mousePositionX/32)+1 ));
            auxY = ((int)(mousePositionY/32)+1);
         }else if ( auxX < 16 && auxY > 16 ){
            auxX = ((int)(mousePositionX/32));
            auxY = ((int)((mousePositionY/32)+1));
         }else{
            auxX = ((int)(mousePositionX/32));
            auxY = ((int)(mousePositionY/32));
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

void EditorEventHandler::renderTiles
(std::vector<Tile*>& tiles,std::vector<Tile*>& optionTiles){
   for (auto& tile: tiles){     
      int xOffset(tile->getX());
      int yOffset(tile->getY());
      int type(tile->getType());
      tile->setMBox(tileClips[type-1]);

      Area finalArea(xOffset,yOffset, 
                       tileClips[type-1].w, tileClips[type-1].h);
      tile->render(finalArea);
   }

   for (auto& optionTile: optionTiles){     
      int xOffset(optionTile->getX());
      int yOffset(optionTile->getY());
      int type(optionTile->getType());
      optionTile->setMBox(tileClips[type-1]);

      Area finalArea(xOffset,yOffset, 
                       tileClips[type-1].w, tileClips[type-1].h);
      optionTile->render(finalArea);
   }
}

void EditorEventHandler::buildTileClips(){
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
}

EditorEventHandler::~EditorEventHandler(){}
