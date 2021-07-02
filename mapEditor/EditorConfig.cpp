#include "EditorConfig.h"

EditorConfig::EditorConfig(const char* mapName):
fileNode(),readerNode(),mapName(mapName){
    createFile();
}

void EditorConfig::createFile(){
    std::ofstream file("editor_config.yaml");

    fileNode["dust"][0]="assets/gfx/tiles/default_dust.png";
    fileNode["dust"][1][0] = YAML::Load("[box ,21, 0, 500]");
    fileNode["dust"][1][1] = YAML::Load("[box ,22, 0, 548]");
    fileNode["dust"][1][2] = YAML::Load("[box ,23, 48, 500]");
    fileNode["dust"][1][3] = YAML::Load("[box ,24, 48, 548]");
    fileNode["dust"][1][4] = YAML::Load("[box ,25, 98, 500]");
    fileNode["dust"][1][5] = YAML::Load("[box ,26, 98, 548]");
    fileNode["dust"][1][6] = YAML::Load("[box ,27, 146, 500]");
    fileNode["dust"][1][7] = YAML::Load("[box ,28, 146, 548]");
    fileNode["dust"][1][8] = YAML::Load("[box ,29, 194, 548]");
    fileNode["dust"][1][9] = YAML::Load("[box ,30, 194, 500]");
    fileNode["dust"][2][0] = YAML::Load("[floor ,2, 0, 500]");
    fileNode["dust"][2][1] = YAML::Load("[floor ,51, 0, 548]");
    fileNode["dust"][2][2] = YAML::Load("[floor ,52, 48, 500]");
    fileNode["dust"][2][3] = YAML::Load("[floor ,53, 48, 548]");
    fileNode["dust"][2][4] = YAML::Load("[floor ,54, 98, 500]");
    fileNode["dust"][2][5] = YAML::Load("[floor ,55, 98, 548]");
    fileNode["dust"][2][6] = YAML::Load("[floor ,56, 146, 500]");
    fileNode["dust"][2][7] = YAML::Load("[floor ,57, 146, 548]");
    fileNode["dust"][2][8] = YAML::Load("[floor ,58, 194, 548]");
    fileNode["dust"][2][9] = YAML::Load("[floor ,59, 194, 500]");
    fileNode["dust"][2][10] = YAML::Load("[floor ,60, 244, 500]");
    fileNode["dust"][3][0] = YAML::Load("[misc ,61, 0, 500]");
    fileNode["dust"][3][1] = YAML::Load("[misc ,62, 48, 500]");
    fileNode["dust"][3][2] = YAML::Load("[misc ,63, 98, 500]");
    fileNode["dust"][3][3] = YAML::Load("[misc ,65, 48, 548]");
    fileNode["dust"][3][4] = YAML::Load("[misc ,70, 0, 548]");
    fileNode["dust"][4][0] = YAML::Load("[wall ,3, 0, 500]");
    fileNode["dust"][4][1] = YAML::Load("[wall ,4, 0, 548]");
    fileNode["dust"][4][2] = YAML::Load("[wall ,5, 48, 500]");
    fileNode["dust"][4][3] = YAML::Load("[wall ,38, 48, 548]");
    fileNode["dust"][4][4] = YAML::Load("[wall ,39, 98, 500]");
    fileNode["dust"][4][5] = YAML::Load("[wall ,43, 98, 548]");
    fileNode["dust"][4][6] = YAML::Load("[wall ,44, 146, 500]");


    fileNode["aztec"][0]="assets/gfx/tiles/default_aztec.png";
    fileNode["aztec"][1][0] = YAML::Load("[box ,21, 0, 500]");
    fileNode["aztec"][1][1] = YAML::Load("[box ,22, 48, 500]");
    fileNode["aztec"][1][2] = YAML::Load("[box ,23, 98, 500]");
    fileNode["aztec"][1][3] = YAML::Load("[box ,26, 0, 548]");
    fileNode["aztec"][1][4] = YAML::Load("[box ,27, 48, 548]");
    fileNode["aztec"][2][0] = YAML::Load("[floor ,2, 0, 500]");
    fileNode["aztec"][2][1] = YAML::Load("[floor ,3, 48, 500]");
    fileNode["aztec"][2][2] = YAML::Load("[floor ,4, 98, 500]");
    fileNode["aztec"][3][0] = YAML::Load("[misc ,38, 0, 500]");
    fileNode["aztec"][3][1] = YAML::Load("[misc ,39, 48, 500]");
    fileNode["aztec"][3][2] = YAML::Load("[misc ,43, 0, 548]");
    fileNode["aztec"][3][3] = YAML::Load("[misc ,44, 48, 548]");
    fileNode["aztec"][4][0] = YAML::Load("[wall ,7, 0, 500]");
    fileNode["aztec"][4][1] = YAML::Load("[wall ,11, 0, 548]");
    fileNode["aztec"][4][2] = YAML::Load("[wall ,8, 48, 500]");
    fileNode["aztec"][4][3] = YAML::Load("[wall ,12, 48, 548]");
    fileNode["aztec"][4][4] = YAML::Load("[wall ,9, 98, 500]");
    fileNode["aztec"][4][5] = YAML::Load("[wall ,13, 98, 548]");
    fileNode["aztec"][4][6] = YAML::Load("[wall ,14, 146, 500]");
    fileNode["aztec"][4][7] = YAML::Load("[wall ,16, 146, 548]");
    fileNode["aztec"][4][8] = YAML::Load("[wall ,17, 194, 548]");
    fileNode["aztec"][4][9] = YAML::Load("[wall ,18, 194, 500]");
    fileNode["aztec"][4][10] = YAML::Load("[wall ,19, 242, 500]");


    fileNode["inferno"][0]="assets/gfx/tiles/default_inferno.png";
    fileNode["inferno"][1][0] = YAML::Load("[box ,21, 0, 500]");
    fileNode["inferno"][1][1] = YAML::Load("[box ,22, 0, 548]");
    fileNode["inferno"][1][2] = YAML::Load("[box ,23, 48, 500]");
    fileNode["inferno"][1][3] = YAML::Load("[box ,24, 48, 548]");
    fileNode["inferno"][1][4] = YAML::Load("[box ,25, 98, 500]");
    fileNode["inferno"][1][5] = YAML::Load("[box ,26, 98, 548]");
    fileNode["inferno"][1][6] = YAML::Load("[box ,27, 146, 500]");
    fileNode["inferno"][1][7] = YAML::Load("[box ,28, 146, 548]");
    fileNode["inferno"][1][8] = YAML::Load("[box ,29, 194, 548]");
    fileNode["inferno"][1][9] = YAML::Load("[box ,30, 194, 500]");
    fileNode["inferno"][1][10] = YAML::Load("[box ,31, 242, 500]");
    fileNode["inferno"][1][11] = YAML::Load("[box ,32, 242, 548]");
    fileNode["inferno"][1][12] = YAML::Load("[box ,33, 290, 500]");
    fileNode["inferno"][1][13] = YAML::Load("[box ,34, 290, 548]");
    fileNode["inferno"][1][14] = YAML::Load("[box ,35, 338, 500]");
    fileNode["inferno"][2][0] = YAML::Load("[floor ,2, 0, 500]");
    fileNode["inferno"][2][1] = YAML::Load("[floor ,5, 0, 548]");
    fileNode["inferno"][2][2] = YAML::Load("[floor ,58, 48, 500]");
    fileNode["inferno"][2][3] = YAML::Load("[floor ,59, 48, 548]");
    fileNode["inferno"][2][4] = YAML::Load("[floor ,60, 98, 500]");
    fileNode["inferno"][2][5] = YAML::Load("[floor ,61, 98, 548]");
    fileNode["inferno"][2][6] = YAML::Load("[floor ,62, 146, 500]");
    fileNode["inferno"][2][7] = YAML::Load("[floor ,63, 146, 548]");
    fileNode["inferno"][2][8] = YAML::Load("[floor ,64, 194, 548]");
    fileNode["inferno"][2][9] = YAML::Load("[floor ,65, 194, 500]");
    fileNode["inferno"][2][10] = YAML::Load("[floor ,66, 242, 500]");
    fileNode["inferno"][2][11] = YAML::Load("[floor ,67, 242, 548]");
    fileNode["inferno"][2][12] = YAML::Load("[floor ,68, 290, 500]");
    fileNode["inferno"][2][13] = YAML::Load("[floor ,69, 290, 548]");
    fileNode["inferno"][2][14] = YAML::Load("[floor ,70, 338, 500]");
    fileNode["inferno"][3][0] = YAML::Load("[misc ,71, 0, 500]");
    fileNode["inferno"][3][1] = YAML::Load("[misc ,72, 0, 548]");
    fileNode["inferno"][3][2] = YAML::Load("[misc ,73, 48, 500]");
    fileNode["inferno"][3][3] = YAML::Load("[misc ,74, 48, 548]");
    fileNode["inferno"][4][0] = YAML::Load("[wall ,3, 0, 500]");
    fileNode["inferno"][4][1] = YAML::Load("[wall ,4, 0, 548]");
    fileNode["inferno"][4][2] = YAML::Load("[wall ,6, 48, 500]");
    fileNode["inferno"][4][3] = YAML::Load("[wall ,7, 48, 548]");
    fileNode["inferno"][4][4] = YAML::Load("[wall ,8, 98, 500]");
    fileNode["inferno"][4][5] = YAML::Load("[wall ,9, 98, 548]");
    fileNode["inferno"][4][6] = YAML::Load("[wall ,10, 146, 500]");
    fileNode["inferno"][4][7] = YAML::Load("[wall ,15, 146, 548]");
    fileNode["inferno"][4][8] = YAML::Load("[wall ,20, 194, 548]");
    fileNode["inferno"][4][9] = YAML::Load("[wall ,33, 194, 500]");
    fileNode["inferno"][4][10] = YAML::Load("[wall ,34, 242, 500]");
    fileNode["inferno"][4][11] = YAML::Load("[wall ,38, 242, 548]");
    fileNode["inferno"][4][12] = YAML::Load("[wall ,39, 290, 500]");

    file << fileNode;

    file.close();
}

void EditorConfig::getAtributes(std::string atributeName,
                                std::vector<Tile*>& options,const Image& image){
    readerNode = YAML::LoadFile("editor_config.yaml");

    int atributeNumber(getAtributeNumber(atributeName));

    for(size_t i=0; i<readerNode[mapName][atributeNumber].size(); i++){
        options.push_back(new Tile(readerNode[mapName][atributeNumber][i][1].as<int>(),
                                   readerNode[mapName][atributeNumber][i][2].as<int>(),
                                   readerNode[mapName][atributeNumber][i][3].as<int>(),
                                   image));
    }
}

int EditorConfig:: getAtributeNumber(const std::string& name){
    if (name=="box"){
        return BOX;
    }else if (name=="floor"){
        return FLOOR;
    }else if (name=="misc"){
        return MISC;
    }else if (name=="wall"){
        return WALL;
    }

    return -1;
}

EditorConfig::~EditorConfig(){}
