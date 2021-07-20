#ifndef _PHYSICAL_MAP_FACTORY_H
#define _PHYSICAL_MAP_FACTORY_H
#include "yaml-cpp/yaml.h"
#include "World.h"
#include "Obstacle.h"
#include "Border.h"
#include <list>
#include <memory>

class Game;
class PhysicalMapFactory {
private:
    World &world;
    YAML::Node map;
    std::unique_ptr<Border> border;
    std::list<std::unique_ptr<Obstacle>> obstacles;
    Game &game;
    int width; 
    int height; 
public:
    PhysicalMapFactory(World &w,std::string mapName, Game &game);
    Border* createBorders();
    void setTerroristsPositions();
    void setCounterTerroristsPositions();
    void setWeaponsPositions();
    int getWidth();
    int getHeight();
};



#endif