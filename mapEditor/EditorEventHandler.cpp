#include "EditorEventHandler.h"
#include "Image.h"
#include "MapEditor.h"

EditorEventHandler::EditorEventHandler(Window& window,Image& image,
                                       Image& obsImage,const char* mapName): 
leftMouseButtonDown(false),mousePositionX(0),mousePositionY(0),
windowWidth(window.getWidth()),windowHeight(window.getHeight()),tileNumber(-1),
actualType(-1),selectedZoneX(windowWidth/2+4),selectedZoneY(windowHeight-86),
image(image),obsImage(obsImage),actualImage(""),window(window),
finalMap(),mapName(mapName){}

bool EditorEventHandler::handleEvents
(std::vector<Tile*>& tiles, std::vector<Tile*>& optionTiles,
std::vector<Tile*>& obstaclesOptionTiles,std::vector<Button*>& buttons,
const std::string& sizeName){
   SDL_Event event;

   buildTileClips();

   while (SDL_PollEvent(&event)){
      switch (event.type) {
         case SDL_MOUSEMOTION:
            mouseMotionHandler(event, tiles);
            break;

         case SDL_MOUSEBUTTONDOWN:
            mouseMotionDown(event, tiles, optionTiles, obstaclesOptionTiles, buttons, sizeName);
            break;

         case SDL_MOUSEBUTTONUP:
            mouseMotionUp(event, tiles);
            break;

         case SDL_QUIT:
            MapEditor map;
            map.createMap("MapaDePruebaEditor",mapName);
            for (auto& e : finalMap){
               map.addField(e.first.first,e.first.second,e.second);
            }
            map.generateMap();
            return false;
        }
   }

   renderTiles(tiles,optionTiles,obstaclesOptionTiles);

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
(SDL_Event& event,std::vector<Tile*>& tiles,std::vector<Tile*>& optionTiles,
std::vector<Tile*>& obstaclesOptionTiles,std::vector<Button*>& buttons, 
const std::string& sizeName){
   if (!leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT){ 
      leftMouseButtonDown = true;
      for (auto& button: buttons){
         if (button->mouseInText(mousePositionX,mousePositionY))
            button->clicked(optionTiles,obstaclesOptionTiles,image,obsImage,sizeName);
      }
      for (auto& tile : optionTiles){
         if (mouseInTile(mousePositionX,mousePositionY,tile)){
            actualType = tile->getType();
            optionTiles.push_back(new Tile(tile->getType(),
                           selectedZoneX,selectedZoneY,image));
            changeActualImage("no_obstacle");
            break;
         }
      }
      for (auto& tile : obstaclesOptionTiles){
         if (mouseInTile(mousePositionX,mousePositionY,tile)){
            actualType = tile->getType();
            optionTiles.push_back(new Tile(tile->getType(),
                           selectedZoneX,selectedZoneY,obsImage));
            changeActualImage("obstacle");
            break;
         }
      }

      if (mouseInGrid(mousePositionX,mousePositionY) && actualType!=-1){
         tiles.push_back(new Tile(actualType,
                           mousePositionX,mousePositionY,getActualImage()));
         tileNumber=(tiles.size()-1);
         putTileInCorrectPosition(tiles[tileNumber]);
         finalMap[std::make_pair(tiles[tileNumber]->getX()/PPM,
                                 tiles[tileNumber]->getY()/PPM)] = tiles[tileNumber]->getType();
      }
   }
}

void EditorEventHandler::mouseMotionUp
(SDL_Event& event, std::vector<Tile*>& tiles){
   leftMouseButtonDown = false;
}

void EditorEventHandler::renderTiles
(std::vector<Tile*>& tiles,std::vector<Tile*>& optionTiles,
std::vector<Tile*>& obstaclesOptionTiles){
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

   for (auto& optionTile: obstaclesOptionTiles){     
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

void EditorEventHandler::putTileInCorrectPosition(Tile* tile){
   int auxX(mousePositionX/32);
   int auxY(mousePositionY/32);

   tile->setX(auxX*32);
   tile->setY(auxY*32);
}

Image& EditorEventHandler::getActualImage(){
  if (actualImage == "obstacle")
    return obsImage;
  return image;
}

void EditorEventHandler::changeActualImage(const std::string& newImage){
  actualImage = newImage;
}

EditorEventHandler::~EditorEventHandler(){}
