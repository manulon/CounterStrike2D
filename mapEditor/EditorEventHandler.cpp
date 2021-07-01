#include "EditorEventHandler.h"
#include "Image.h"
#include "MapEditor.h"

EditorEventHandler::EditorEventHandler(Window& window,const Image& image): 
leftMouseButtonDown(false),mousePositionX(0),mousePositionY(0),
windowWidth(window.getWidth()),windowHeight(window.getHeight()),tileNumber(-1),
actualType(-1),selectedZoneX(384),selectedZoneY(500),image(image){}

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
}

void EditorEventHandler::mouseMotionDown
(SDL_Event& event,std::vector<Tile*>& tiles,std::vector<Tile*>& optionTiles){
   if (!leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT){ 
      leftMouseButtonDown = true;
      for (auto& tile : optionTiles){
         if (mouseInTile(mousePositionX,mousePositionY,tile)){
            actualType = tile->getType();
            optionTiles.push_back(new Tile(tile->getType(),
                           selectedZoneX,selectedZoneY,image));
            break;
         }
      }
      if (mouseInGrid(mousePositionX,mousePositionY) && actualType!=-1){
         tiles.push_back(new Tile(actualType,
                           mousePositionX,mousePositionY,image));
         tileNumber=(tiles.size()-1);
         checkPosition(tiles[tileNumber]);
      }
   }
}

void EditorEventHandler::mouseMotionUp
(SDL_Event& event, std::vector<Tile*>& tiles){
   leftMouseButtonDown = false;
   for (auto& tile : tiles){
      checkPosition(tile);
   }
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

bool EditorEventHandler::mouseInGrid(int mousePositionX,int mousePositionY){
   if ( (mousePositionX >= 0) && (mousePositionX < windowWidth) && 
        (mousePositionY >= 0) && (mousePositionY < windowHeight - 128)){
      return true;
   }
   return false;
}

void EditorEventHandler::checkPosition(Tile* tile){
   if (tile->tileOutOfPosition()){
         int auxX(mousePositionX/32);
         int auxY(mousePositionY/32);

         tile->setX(auxX*32);
         tile->setY(auxY*32);
      }
}

EditorEventHandler::~EditorEventHandler(){}
