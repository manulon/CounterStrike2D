#include <iostream>
#include <fstream>
#include <vector>
#include "MapEditor.h"

int main(){
    std::ofstream file("editor_config.yaml");
    YAML::Node fileNode;


    fileNode["dust"]["small"][0] = YAML::Load("[box ,21, 0, 500]");
    fileNode["dust"]["small"][1] = YAML::Load("[box ,22, 0, 548]");
    fileNode["dust"]["small"][2] = YAML::Load("[box ,23, 48, 500]");
    fileNode["dust"]["small"][3] = YAML::Load("[box ,24, 48, 548]");
    file << fileNode;

    file.close();

    YAML::Node mapRead = YAML::LoadFile("editor_config.yaml");
    std::cout<<"Lei: "<<mapRead["dust"]["small"][0][0]<<std::endl;
    //std::cout<<"Lei: "<<mapRead["atributes"][0][1]<<std::endl;

    return 0;
}