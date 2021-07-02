#include <iostream>
#include <fstream>
#include <vector>
#include "MapEditor.h"

int main(){
    std::ofstream file("editor_config.yaml");
    YAML::Node test;

    test["dust"][0]="assets/gfx/tiles/default_dust.png";
    test["dust"][1][0] = YAML::Load("[box ,21, 0, 500]");
    test["dust"][1][1] = YAML::Load("[box ,22, 0, 548]");
    test["dust"][1][2] = YAML::Load("[box ,23, 48, 500]");
    test["dust"][1][3] = YAML::Load("[box ,24, 48, 548]");
    test["dust"][1][4] = YAML::Load("[box ,25, 98, 500]");
    test["dust"][1][5] = YAML::Load("[box ,26, 98, 548]");
    test["dust"][1][6] = YAML::Load("[box ,27, 146, 500]");
    test["dust"][1][7] = YAML::Load("[box ,28, 146, 548]");
    test["dust"][1][8] = YAML::Load("[box ,29, 194, 548]");
    test["dust"][1][9] = YAML::Load("[box ,30, 194, 500]");
    test["dust"][2][0] = YAML::Load("[floor ,2, 0, 500]");
    test["dust"][2][1] = YAML::Load("[floor ,51, 0, 548]");
    test["dust"][2][2] = YAML::Load("[floor ,52, 48, 500]");
    test["dust"][2][3] = YAML::Load("[floor ,53, 48, 548]");
    test["dust"][2][4] = YAML::Load("[floor ,54, 98, 500]");
    test["dust"][2][5] = YAML::Load("[floor ,55, 98, 548]");
    test["dust"][2][6] = YAML::Load("[floor ,56, 146, 500]");
    test["dust"][2][7] = YAML::Load("[floor ,57, 146, 548]");
    test["dust"][2][8] = YAML::Load("[floor ,58, 194, 548]");
    test["dust"][2][9] = YAML::Load("[floor ,59, 194, 500]");
    test["dust"][3][0] = YAML::Load("[floor ,60, 244, 500]");
    test["dust"][3][1] = YAML::Load("[misc ,61, 0, 500]");
    test["dust"][3][2] = YAML::Load("[misc ,62, 48, 500]");
    test["dust"][3][3] = YAML::Load("[misc ,63, 98, 500]");
    test["dust"][3][4] = YAML::Load("[misc ,65, 48, 548]");
    test["dust"][3][5] = YAML::Load("[misc ,70, 0, 548]");
    test["dust"][4][0] = YAML::Load("[wall ,3, 0, 500]");
    test["dust"][4][1] = YAML::Load("[wall ,4, 0, 548]");
    test["dust"][4][2] = YAML::Load("[wall ,5, 48, 500]");
    test["dust"][4][3] = YAML::Load("[wall ,38, 48, 548]");
    test["dust"][4][4] = YAML::Load("[wall ,39, 98, 500]");
    test["dust"][4][5] = YAML::Load("[wall ,43, 98, 548]");
    test["dust"][4][6] = YAML::Load("[wall ,44, 146, 500]");


    test["aztec"][0]="assets/gfx/tiles/default_aztec.png";
    test["aztec"][1][0] = YAML::Load("[box ,21, 0, 500]");
    test["aztec"][1][1] = YAML::Load("[box ,22, 48, 500]");
    test["aztec"][1][2] = YAML::Load("[box ,23, 98, 500]");
    test["aztec"][1][3] = YAML::Load("[box ,26, 0, 548]");
    test["aztec"][1][4] = YAML::Load("[box ,27, 48, 548]");
    test["aztec"][2][0] = YAML::Load("[floor, ,2, 0, 500]");
    test["aztec"][2][1] = YAML::Load("[floor ,3, 48, 500]");
    test["aztec"][2][2] = YAML::Load("[floor ,4, 98, 500]");
    test["aztec"][2][3] = YAML::Load("[floor ,38, 148, 500]");
    test["aztec"][2][4] = YAML::Load("[floor ,39, 0, 548]");
    test["aztec"][2][5] = YAML::Load("[floor ,43, 48, 548]");
    test["aztec"][2][6] = YAML::Load("[floor ,44, 98, 548]");
    test["aztec"][3][0] = YAML::Load("[misc ,61, 0, 500]");
    test["aztec"][3][1] = YAML::Load("[misc ,62, 48, 500]");
    test["aztec"][3][2] = YAML::Load("[misc ,63, 98, 500]");
    test["aztec"][3][3] = YAML::Load("[misc ,65, 48, 548]");
    test["aztec"][3][4] = YAML::Load("[misc ,70, 0, 548]");
    test["aztec"][4][0] = YAML::Load("[wall ,7, 0, 500]");
    test["aztec"][4][1] = YAML::Load("[wall ,11, 0, 548]");
    test["aztec"][4][2] = YAML::Load("[wall ,8, 48, 500]");
    test["aztec"][4][3] = YAML::Load("[wall ,12, 48, 548]");
    test["aztec"][4][4] = YAML::Load("[wall ,9, 98, 500]");
    test["aztec"][4][5] = YAML::Load("[wall ,13, 98, 548]");
    test["aztec"][4][6] = YAML::Load("[wall ,14, 146, 500]");
    test["aztec"][4][7] = YAML::Load("[wall ,16, 146, 548]");
    test["aztec"][4][8] = YAML::Load("[wall ,17, 194, 548]");
    test["aztec"][4][9] = YAML::Load("[wall ,18, 194, 500]");
    test["aztec"][4][10] = YAML::Load("[wall ,19, 242, 500]");


    test["inferno"][0]="assets/gfx/tiles/default_inferno.png";
    test["inferno"][1][0] = YAML::Load("[box ,21, 0, 500]");
    test["inferno"][1][1] = YAML::Load("[box ,22, 0, 548]");
    test["inferno"][1][2] = YAML::Load("[box ,23, 48, 500]");
    test["inferno"][1][3] = YAML::Load("[box ,24, 48, 548]");
    test["inferno"][1][4] = YAML::Load("[box ,25, 98, 500]");
    test["inferno"][1][5] = YAML::Load("[box ,26, 98, 548]");
    test["inferno"][1][6] = YAML::Load("[box ,27, 146, 500]");
    test["inferno"][1][7] = YAML::Load("[box ,28, 146, 548]");
    test["inferno"][1][8] = YAML::Load("[box ,29, 194, 548]");
    test["inferno"][1][9] = YAML::Load("[box ,30, 194, 500]");
    test["inferno"][1][10] = YAML::Load("[box ,31, 242, 500]");
    test["inferno"][1][11] = YAML::Load("[box ,32, 242, 548]");
    test["inferno"][1][12] = YAML::Load("[box ,33, 290, 500]");
    test["inferno"][1][13] = YAML::Load("[box ,34, 290, 548]");
    test["inferno"][1][14] = YAML::Load("[box ,35, 338, 500]");
    test["inferno"][2][0] = YAML::Load("[floor ,2, 0, 500]");
    test["inferno"][2][1] = YAML::Load("[floor ,5, 0, 548]");
    test["inferno"][2][2] = YAML::Load("[floor ,58, 48, 500]");
    test["inferno"][2][3] = YAML::Load("[floor ,59, 48, 548]");
    test["inferno"][2][4] = YAML::Load("[floor ,60, 98, 500]");
    test["inferno"][2][5] = YAML::Load("[floor ,61, 98, 548]");
    test["inferno"][2][6] = YAML::Load("[floor ,62, 146, 500]");
    test["inferno"][2][7] = YAML::Load("[floor ,63, 146, 548]");
    test["inferno"][2][8] = YAML::Load("[floor ,64, 194, 548]");
    test["inferno"][2][9] = YAML::Load("[floor ,65, 194, 500]");
    test["inferno"][2][10] = YAML::Load("[floor ,66, 242, 500]");
    test["inferno"][2][11] = YAML::Load("[floor ,67, 242, 548]");
    test["inferno"][2][12] = YAML::Load("[floor ,68, 290, 500]");
    test["inferno"][2][13] = YAML::Load("[floor ,69, 290, 548]");
    test["inferno"][2][14] = YAML::Load("[floor ,70, 338, 500]");
    test["inferno"][3][0] = YAML::Load("[misc ,66, 0, 500]");
    test["inferno"][3][1] = YAML::Load("[misc ,67, 0, 548]");
    test["inferno"][3][2] = YAML::Load("[misc ,68, 48, 500]");
    test["inferno"][3][3] = YAML::Load("[misc ,69, 48, 548]");
    test["inferno"][4][0] = YAML::Load("[wall ,3, 0, 500]");
    test["inferno"][4][1] = YAML::Load("[wall ,4, 0, 548]");
    test["inferno"][4][2] = YAML::Load("[wall ,6, 48, 500]");
    test["inferno"][4][3] = YAML::Load("[wall ,7, 48, 548]");
    test["inferno"][4][4] = YAML::Load("[wall ,8, 98, 500]");
    test["inferno"][4][5] = YAML::Load("[wall ,9, 98, 548]");
    test["inferno"][4][6] = YAML::Load("[wall ,10, 146, 500]");
    test["inferno"][4][7] = YAML::Load("[wall ,15, 146, 548]");
    test["inferno"][4][8] = YAML::Load("[wall ,20, 194, 548]");
    test["inferno"][4][9] = YAML::Load("[wall ,33, 194, 500]");
    test["inferno"][4][10] = YAML::Load("[wall ,34, 242, 500]");
    test["inferno"][4][11] = YAML::Load("[wall ,38, 242, 548]");
    test["inferno"][4][12] = YAML::Load("[wall ,39, 290, 500]");
    

    file << test;

    file.close();

    //YAML::Node mapRead = YAML::LoadFile("editor_config.yaml");
    //std::cout<<"Lei: "<<mapRead["atributes"][16][0][0]<<std::endl;
    //std::cout<<"Lei: "<<mapRead["atributes"][0][1]<<std::endl;

    return 0;
}