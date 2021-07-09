#include "MapEditor.h"

MapEditor::MapEditor(/* args */)
{
}

MapEditor::~MapEditor()
{
}
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
    std::ofstream file(mapName+".yaml");
    file<<map;
    file.close();
}

void MapEditor::addSize(std::string size){
    map["size"] = size;
}