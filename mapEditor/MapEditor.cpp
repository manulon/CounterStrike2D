#include "MapEditor.h"

MapEditor::MapEditor(/* args */):
mapNameFile("../assets/maps/map_names.yaml"){}

MapEditor::~MapEditor(){}

void MapEditor::createMap(std::string name, std::string style) {
    mapName = name;
    map["style"] = style;
}
void MapEditor::addField(int x ,int y , int sprite){
    YAML::Node field = YAML::Load("["+std::to_string(x)+","+std::to_string(y)+","+std::to_string(sprite)+"]");
    map["fields"].push_back(field); 
}
void MapEditor::addObstacle(int x, int y, int sprite){
    YAML::Node obstacle = YAML::Load("["+std::to_string(x)+","+std::to_string(y)+","+std::to_string(sprite)+"]");
    map["obstacles"].push_back(obstacle);
}
void MapEditor::generateMap(){
    std::ofstream file("../assets/maps/"+mapName+".yaml");
    file<<map;
    file.close();

    addMap();
}

void MapEditor::addMap(){ 
    YAML::Node readerNodeDataBase = YAML::LoadFile("../assets/maps/mapsDataBase.yaml");
    
    readerNodeDataBase["mapName"][readerNodeDataBase["mapName"].size()] = "../assets/maps/"+mapName+".yaml";
    
    mapNameFile << readerNodeDataBase;
    
    std::ofstream mapNameDatabase("../assets/maps/mapsDataBase.yaml");
    mapNameDatabase << readerNodeDataBase;
    
    mapNameDatabase.close();
    mapNameFile.close();
}

void MapEditor::addSize(std::string size){
    map["size"] = size;
}

void MapEditor::addTerrorist(int x , int y){
    YAML::Node field = YAML::Load("["+std::to_string(x)+","+std::to_string(y)+"]");
    map["terrorist"].push_back(field); 
}

void MapEditor::addCounterTerrorist(int x , int y){
    YAML::Node field = YAML::Load("["+std::to_string(x)+","+std::to_string(y)+"]");
    map["counter-terrorist"].push_back(field);
}

void MapEditor::addWeapon(int x , int y, int id){
    YAML::Node field = YAML::Load("["+std::to_string(x)+","+std::to_string(y)+","+std::to_string(id)+"]");
    map["weapon"].push_back(field);
}
