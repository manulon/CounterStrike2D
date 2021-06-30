#include <iostream>
#include <fstream>
#include <vector>
#include "MapEditor.h"

// int main(int argc, char const *argv[]){
//     int spriteId;
//     MapEditor me;
//     me.createMap("mapTest", "dust");
//     std::fstream file("testMap.txt");
//     int x_aux(0);
//     int y_aux(0);
//     for (int i = 0; i<650;i++){
//         file >> spriteId;
//         me.addField(x_aux,y_aux,spriteId);
//         x_aux += 1;

//         if (x_aux==25){
//         	x_aux=0;
//         	y_aux+=1;
//         }

//     } 
//     me.addObstacle(14,1,21);
//     me.generateMap();
//     return 0;
// }

int main(int argc, char **argv){
    YAML::Node map = YAML::LoadFile("mapaDeFede.yaml");
    YAML::Node fieldsx = map["fields"];
    for (unsigned int i = 0; i <fieldsx.size(); i++){
        std::cout<<fieldsx[i]<<std::endl;
    }
    
}