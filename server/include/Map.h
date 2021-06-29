#ifndef _MAP_H
#define _MAP_H
#include "yaml-cpp/yaml.h"
#include "World.h"
#include "Obstacle.h"
#include <list>
#include <memory>
class Map {
private:
    World &world;
    std::list<std::unique_ptr<Obstacle>> obstacles;
public:
    Map(World &w,std::string mapName);
    ~Map();
};

Map::Map(World &w, std::string mapName) : world(w) {
    YAML::Node map = YAML::LoadFile(mapName);
    YAML::Node obstacles = map["obstacles"];
    for (int i = 0; i < obstacles.size();i++){
        obstacles.push_back(make_unique<Obstacle>(world, ))
    }
}

Map::~Map()
{
}


#endif