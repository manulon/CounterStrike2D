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
    std::ofstream mapNameFile;

    void addMap();

public:
    MapEditor();
    ~MapEditor();
    void createMap(std::string name, std::string style);
    void addField(int x , int y, int sprite);
    void addObstacle(int x , int y, int sprite);
    void addTerrorist(int x , int y);
    void addCounterTerrorist(int x , int y);
    void addWeapon(int x , int y, int id);
    void generateMap();
    void addSize(std::string name);

};


#endif