#ifndef _MAP_PARSER_H
#define _MAP_PARSER_H
#include <string>
#include "yaml-cpp/yaml.h"
class MapParser{
private:
    std::string fileName;
public:
    MapParser(std::string name) : fileName(name){}
    void getFields();
};

void MapParser::getFields(){
    YAML::Node map = YAML::LoadFile(fileName);
    YAML::Node fields = map["fields"];
    for (unsigned int i = 0, i < fields.size(); i++){
        
    }
}

#endif
