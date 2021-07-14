#include "EditorEventHandler.h"
#include "Image.h"
#include "MapEditor.h"
#include <iostream>

EditorEventHandler::EditorEventHandler(Window& window,Image& image,
                                       Image& obsImage,const char* mapName): 
leftMouseButtonDown(false),mousePositionX(0),mousePositionY(0),
windowWidth(window.getWidth()),windowHeight(window.getHeight()),tileNumber(-1),
actualType(-1),selectedZoneX(windowWidth/2+4),selectedZoneY(windowHeight-86),
image(image),obsImage(obsImage),actualImage(""),window(window),
finalMapTiles(),finalMapObstacles(),mapName(mapName),
tileBoxHeight(0),tileWidth(0),tileHeight(0){
   YAML::Node readerNode = YAML::LoadFile("../assets/config/editor_config.yaml");
   tileBoxHeight = readerNode["config"]["tile_box_height"].as<int>();
   tileWidth     = readerNode["config"]["tile_width"].as<int>();
   tileHeight    = readerNode["config"]["tile_height"].as<int>();
}

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
            std::cout<<"Ingrese el nombre del mapa: "<<std::endl;
            std::string input("");
            while (input != "") {
              std::cin >> input;
            }
            std::cout<<"Se ha creado un mapa con el nombre "<<input<<std::endl;
            map.addSize(sizeName);
            map.createMap(input,mapName);
            for (auto& e : finalMapTiles){
               map.addField(e.first.first,e.first.second,e.second);
            }
            for (auto& e : finalMapObstacles){
               map.addObstacle(e.first.first,e.first.second,e.second);
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
         if (actualImage == "obstacle"){
            finalMapObstacles[std::make_pair(tiles[tileNumber]->getX()/PPM,
                                             tiles[tileNumber]->getY()/PPM)] = tiles[tileNumber]->getType();
         }else{
            finalMapTiles[std::make_pair(tiles[tileNumber]->getX()/PPM,
                                         tiles[tileNumber]->getY()/PPM)] = tiles[tileNumber]->getType();
        }
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
        tileClips[i].w = tileWidth;
        tileClips[i].h = tileHeight;

        x_aux += tileWidth;

        if (x_aux==tileWidth*5){
        	x_aux=0;
        	y_aux+=tileHeight;
        }
   }
}

bool EditorEventHandler::mouseInGrid(int mousePositionX,int mousePositionY){
   if ( (mousePositionX >= 0) && (mousePositionX < windowWidth) && 
        (mousePositionY >= 0) && (mousePositionY < windowHeight - tileBoxHeight)){
      return true;
   }
   return false;
}

void EditorEventHandler::putTileInCorrectPosition(Tile* tile){
   int auxX(mousePositionX/PPM);
   int auxY(mousePositionY/PPM);

   tile->setX(auxX*PPM);
   tile->setY(auxY*PPM);
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
