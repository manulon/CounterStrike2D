#ifndef _MAP_EDITOR_H
#define _MAP_EDITOR_H
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>

class MapEditor{
private:
    /* data */
    YAML::Node map;
    std::string mapName;
public:
    MapEditor();
    ~MapEditor();
    void createMap(std::string name, std::string style);
    void addField(int x , int y, int sprite);
    void addObstacle(int x , int y, int sprite);
    void generateMap();
    void addSize(std::string name);
};


#endif