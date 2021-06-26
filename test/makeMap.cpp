#include <iostream>
#include <fstream>
#include <vector>
#include "MapEditor.h"
// int main(int argc, char const *argv[]){
//     std::ofstream file("map2.yaml");
//     YAML::Node mapFile;

//     mapFile["style"] = "dust";
//     for (int i = 0; i <2; i++){
//         YAML::Node field = YAML::Load("[1,2,3,4,5]");
//         mapFile["fields"].push_back(field);
//     }
//     std::vector<int> lista;
//     lista.push_back(9);
//     lista.push_back(4);
//     lista.push_back(2);
//     lista.push_back(4);
//     lista.push_back(2);
//     std::cout <<(std::stringendl;
//     YAML::Node seq(lista);
//     mapFile["fields"].push_back(seq);
//     file <<mapFile;

//     file.close();

//     // YAML::Node node = YAML::LoadFile("map2.yaml");
//     // if (node["fields"][0].IsSequence()) std::cout<<"pepe\n"; 
//     // std::cout<<node["fields"][0][2]<<std::endl;
//     return 0;
// }
int main(int argc, char const *argv[]){
    MapEditor me;
    me.createMap("mapaDeFede","dust");
    for (int i = 0; i<5 ; i++) me.addField(i,i* 2,i*40);
    for (int i = 0; i<5 ; i++) me.addObstacle(i+5,i*42,i*3);
    me.generateMap();
    return 0;
}

