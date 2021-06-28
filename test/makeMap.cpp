#include <iostream>
#include <fstream>
#include <vector>
#include "MapEditor.h"

int main(int argc, char const *argv[]){
    int spriteId;
    MapEditor me;
    me.createMap("mapTest", "dust");
    std::fstream file("testMap.txt");
    int x_aux(0);
    int y_aux(0);
    for (int i = 0; i<650;i++){
        file >> spriteId;
        me.addField(x_aux,y_aux,spriteId);
        x_aux += 32;

        if (x_aux==800){
        	x_aux=0;
        	y_aux+=32;
        }

    } 
    me.addObstacle(448,32,21);
    me.generateMap();
    return 0;
}

// int main(int argc, char **argv){
//     YAML::Node map = YAML::LoadFile("mapTest.yaml");
//     YAML::Node fields = map["fields"];
//     for (unsigned int i = 0; i < fields.size(); i++ ){
//         std::cout <<fields[i][0]<<", "<<fields[i][1]<<", "<<fields[i][2]<< std::endl;
//         int j  = fields[i][0].as<int>();
//         std::cout <<"el int es: "<< j+3<<std::endl;
//     }
// }