#include "EditorConfig.h"

EditorConfig::EditorConfig(const char* mapName):
fileNode(),readerNode(),mapName(mapName){
    //createFile();
}

void EditorConfig::createFile(){
    /*std::ofstream file("editor_config.yaml");
    
    fileNode["dust"]["small"]["box"][0] = YAML::Load("[21, 0, 360]");
    fileNode["dust"]["small"]["box"][1] = YAML::Load("[22, 0, 408]");
    fileNode["dust"]["small"]["box"][2] = YAML::Load("[23, 48, 360]");
    fileNode["dust"]["small"]["box"][3] = YAML::Load("[24, 48, 408]");
    fileNode["dust"]["small"]["box"][4] = YAML::Load("[25, 98, 360]");
    fileNode["dust"]["small"]["box"][5] = YAML::Load("[26, 98, 408]");
    fileNode["dust"]["small"]["box"][6] = YAML::Load("[27, 146, 360]");
    fileNode["dust"]["small"]["box"][7] = YAML::Load("[28, 146, 408]");
    fileNode["dust"]["small"]["box"][8] = YAML::Load("[29, 194, 408]");
    fileNode["dust"]["small"]["box"][9] = YAML::Load("[30, 194, 360]");
    fileNode["dust"]["small"]["floor"][0] = YAML::Load("[2, 0, 360]");
    fileNode["dust"]["small"]["floor"][1] = YAML::Load("[51, 0, 408]");
    fileNode["dust"]["small"]["floor"][2] = YAML::Load("[52, 48, 360]");
    fileNode["dust"]["small"]["floor"][3] = YAML::Load("[53, 48, 408]");
    fileNode["dust"]["small"]["floor"][4] = YAML::Load("[54, 98, 360]");
    fileNode["dust"]["small"]["floor"][5] = YAML::Load("[55, 98, 408]");
    fileNode["dust"]["small"]["floor"][6] = YAML::Load("[56, 146, 360]");
    fileNode["dust"]["small"]["floor"][7] = YAML::Load("[57, 146, 408]");
    fileNode["dust"]["small"]["floor"][8] = YAML::Load("[58, 194, 408]");
    fileNode["dust"]["small"]["floor"][9] = YAML::Load("[59, 194, 360]");
    fileNode["dust"]["small"]["floor"][10] = YAML::Load("[60, 244, 360]");
    fileNode["dust"]["small"]["misc"][0] = YAML::Load("[61, 0, 360]");
    fileNode["dust"]["small"]["misc"][1] = YAML::Load("[62, 48, 360]");
    fileNode["dust"]["small"]["misc"][2] = YAML::Load("[63, 98, 360]");
    fileNode["dust"]["small"]["misc"][3] = YAML::Load("[65, 48, 408]");
    fileNode["dust"]["small"]["misc"][4] = YAML::Load("[70, 0, 408]");
    fileNode["dust"]["small"]["wall"][0] = YAML::Load("[3, 0, 360]");
    fileNode["dust"]["small"]["wall"][1] = YAML::Load("[4, 0, 408]");
    fileNode["dust"]["small"]["wall"][2] = YAML::Load("[5, 48, 360]");
    fileNode["dust"]["small"]["wall"][3] = YAML::Load("[38, 48, 408]");
    fileNode["dust"]["small"]["wall"][4] = YAML::Load("[39, 98, 360]");
    fileNode["dust"]["small"]["wall"][5] = YAML::Load("[43, 98, 408]");
    fileNode["dust"]["small"]["wall"][6] = YAML::Load("[44, 146, 360]");

    fileNode["aztec"]["small"]["box"][0] = YAML::Load("[21, 0, 360]");
    fileNode["aztec"]["small"]["box"][1] = YAML::Load("[22, 48, 360]");
    fileNode["aztec"]["small"]["box"][2] = YAML::Load("[23, 98, 360]");
    fileNode["aztec"]["small"]["box"][3] = YAML::Load("[26, 0, 408]");
    fileNode["aztec"]["small"]["box"][4] = YAML::Load("[27, 48, 408]");
    fileNode["aztec"]["small"]["floor"][0] = YAML::Load("[2, 0, 360]");
    fileNode["aztec"]["small"]["floor"][1] = YAML::Load("[3, 48, 360]");
    fileNode["aztec"]["small"]["floor"][2] = YAML::Load("[5, 98, 360]");
    fileNode["aztec"]["small"]["misc"][0] = YAML::Load("[38, 0, 360]");
    fileNode["aztec"]["small"]["misc"][1] = YAML::Load("[39, 48, 360]");
    fileNode["aztec"]["small"]["misc"][2] = YAML::Load("[43, 0, 408]");
    fileNode["aztec"]["small"]["misc"][3] = YAML::Load("[44, 48, 408]");
    fileNode["aztec"]["small"]["wall"][0] = YAML::Load("[7, 0, 360]");
    fileNode["aztec"]["small"]["wall"][1] = YAML::Load("[11, 0, 408]");
    fileNode["aztec"]["small"]["wall"][2] = YAML::Load("[8, 48, 360]");
    fileNode["aztec"]["small"]["wall"][3] = YAML::Load("[12, 48, 408]");
    fileNode["aztec"]["small"]["wall"][4] = YAML::Load("[9, 98, 360]");
    fileNode["aztec"]["small"]["wall"][5] = YAML::Load("[13, 98, 408]");
    fileNode["aztec"]["small"]["wall"][6] = YAML::Load("[14, 146, 360]");
    fileNode["aztec"]["small"]["wall"][7] = YAML::Load("[16, 146, 408]");
    fileNode["aztec"]["small"]["wall"][8] = YAML::Load("[17, 194, 408]");
    fileNode["aztec"]["small"]["wall"][9] = YAML::Load("[18, 194, 360]");
    fileNode["aztec"]["small"]["wall"][10] = YAML::Load("[19, 242, 360]");

    fileNode["inferno"]["small"]["box"][0] = YAML::Load("[21, 0, 360]");
    fileNode["inferno"]["small"]["box"][1] = YAML::Load("[22, 48, 360]");
    fileNode["inferno"]["small"]["box"][2] = YAML::Load("[23, 96, 360]");
    fileNode["inferno"]["small"]["box"][3] = YAML::Load("[26, 0, 408]");
    fileNode["inferno"]["small"]["box"][4] = YAML::Load("[27, 48, 408]");
    fileNode["inferno"]["small"]["floor"][0] = YAML::Load("[2, 0, 360]");
    fileNode["inferno"]["small"]["floor"][1] = YAML::Load("[3, 48, 360]");
    fileNode["inferno"]["small"]["floor"][2] = YAML::Load("[5, 0, 408]");
    fileNode["inferno"]["small"]["floor"][3] = YAML::Load("[59, 48, 408]");
    fileNode["inferno"]["small"]["misc"][0]= YAML::Load("[71, 0, 360]");
    fileNode["inferno"]["small"]["misc"][1] = YAML::Load("[72, 0, 408]");
    fileNode["inferno"]["small"]["misc"][2] = YAML::Load("[73, 48, 360]");
    fileNode["inferno"]["small"]["misc"][3] = YAML::Load("[74, 48, 408]");
    fileNode["inferno"]["small"]["wall"][0] = YAML::Load("[39, 0, 360]");
    fileNode["inferno"]["small"]["wall"][1] = YAML::Load("[43, 48, 360]");
    fileNode["inferno"]["small"]["wall"][2] = YAML::Load("[4, 96, 360]");
    fileNode["inferno"]["small"]["wall"][3] = YAML::Load("[38, 0, 408]");
    fileNode["inferno"]["small"]["wall"][4] = YAML::Load("[44, 48, 408]");

    fileNode["dust"]["big"]["box"][0] = YAML::Load("[21, 0, 360]");
    fileNode["dust"]["big"]["box"][1] = YAML::Load("[22, 0, 408]");
    fileNode["dust"]["big"]["box"][2] = YAML::Load("[23, 48, 360]");
    fileNode["dust"]["big"]["box"][3] = YAML::Load("[24, 48, 408]");
    fileNode["dust"]["big"]["box"][4] = YAML::Load("[25, 98, 360]");
    fileNode["dust"]["big"]["box"][5] = YAML::Load("[26, 98, 408]");
    fileNode["dust"]["big"]["box"][6] = YAML::Load("[27, 146, 360]");
    fileNode["dust"]["big"]["box"][7] = YAML::Load("[28, 146, 408]");
    fileNode["dust"]["big"]["box"][8] = YAML::Load("[29, 194, 408]");
    fileNode["dust"]["big"]["box"][9] = YAML::Load("[30, 194, 360]");
    fileNode["dust"]["big"]["floor"][0] = YAML::Load("[2, 0, 360]");
    fileNode["dust"]["big"]["floor"][1] = YAML::Load("[51, 0, 408]");
    fileNode["dust"]["big"]["floor"][2] = YAML::Load("[52, 48, 360]");
    fileNode["dust"]["big"]["floor"][3] = YAML::Load("[53, 48, 408]");
    fileNode["dust"]["big"]["floor"][4] = YAML::Load("[54, 98, 360]");
    fileNode["dust"]["big"]["floor"][5] = YAML::Load("[55, 98, 408]");
    fileNode["dust"]["big"]["floor"][6] = YAML::Load("[56, 146, 360]");
    fileNode["dust"]["big"]["floor"][7] = YAML::Load("[57, 146, 408]");
    fileNode["dust"]["big"]["floor"][8] = YAML::Load("[58, 194, 408]");
    fileNode["dust"]["big"]["floor"][9] = YAML::Load("[59, 194, 360]");
    fileNode["dust"]["big"]["floor"][10] = YAML::Load("[60, 244, 360]");
    fileNode["dust"]["big"]["misc"][0] = YAML::Load("[61, 0, 360]");
    fileNode["dust"]["big"]["misc"][1] = YAML::Load("[62, 48, 360]");
    fileNode["dust"]["big"]["misc"][2] = YAML::Load("[63, 98, 360]");
    fileNode["dust"]["big"]["misc"][3] = YAML::Load("[65, 48, 408]");
    fileNode["dust"]["big"]["misc"][4] = YAML::Load("[70, 0, 408]");
    fileNode["dust"]["big"]["wall"][0] = YAML::Load("[3, 0, 360]");
    fileNode["dust"]["big"]["wall"][1] = YAML::Load("[4, 0, 408]");
    fileNode["dust"]["big"]["wall"][2] = YAML::Load("[5, 48, 360]");
    fileNode["dust"]["big"]["wall"][3] = YAML::Load("[38, 48, 408]");
    fileNode["dust"]["big"]["wall"][4] = YAML::Load("[39, 98, 360]");
    fileNode["dust"]["big"]["wall"][5] = YAML::Load("[43, 98, 408]");
    fileNode["dust"]["big"]["wall"][6] = YAML::Load("[44, 146, 360]");

    fileNode["aztec"]["big"]["box"][0] = YAML::Load("[21, 0, 360]");
    fileNode["aztec"]["big"]["box"][1] = YAML::Load("[22, 48, 360]");
    fileNode["aztec"]["big"]["box"][2] = YAML::Load("[23, 98, 360]");
    fileNode["aztec"]["big"]["box"][3] = YAML::Load("[26, 0, 408]");
    fileNode["aztec"]["big"]["box"][4] = YAML::Load("[27, 48, 408]");
    fileNode["aztec"]["big"]["floor"][0] = YAML::Load("[2, 0, 360]");
    fileNode["aztec"]["big"]["floor"][1] = YAML::Load("[3, 48, 360]");
    fileNode["aztec"]["big"]["floor"][2] = YAML::Load("[4, 98, 360]");
    fileNode["aztec"]["big"]["misc"][0] = YAML::Load("[38, 0, 360]");
    fileNode["aztec"]["big"]["misc"][1] = YAML::Load("[39, 48, 360]");
    fileNode["aztec"]["big"]["misc"][2] = YAML::Load("[43, 0, 408]");
    fileNode["aztec"]["big"]["misc"][3] = YAML::Load("[44, 48, 408]");
    fileNode["aztec"]["big"]["wall"][0] = YAML::Load("[7, 0, 360]");
    fileNode["aztec"]["big"]["wall"][1] = YAML::Load("[11, 0, 408]");
    fileNode["aztec"]["big"]["wall"][2] = YAML::Load("[8, 48, 360]");
    fileNode["aztec"]["big"]["wall"][3] = YAML::Load("[12, 48, 408]");
    fileNode["aztec"]["big"]["wall"][4] = YAML::Load("[9, 98, 360]");
    fileNode["aztec"]["big"]["wall"][5] = YAML::Load("[13, 98, 408]");
    fileNode["aztec"]["big"]["wall"][6] = YAML::Load("[14, 146, 360]");
    fileNode["aztec"]["big"]["wall"][7] = YAML::Load("[16, 146, 408]");
    fileNode["aztec"]["big"]["wall"][8] = YAML::Load("[17, 194, 408]");
    fileNode["aztec"]["big"]["wall"][9] = YAML::Load("[18, 194, 360]");
    fileNode["aztec"]["big"]["wall"][10] = YAML::Load("[19, 242, 360]");

    fileNode["inferno"]["big"]["box"][0] = YAML::Load("[21, 0, 360]");
    fileNode["inferno"]["big"]["box"][1] = YAML::Load("[22, 48, 360]");
    fileNode["inferno"]["big"]["box"][2] = YAML::Load("[23, 96, 360]");
    fileNode["inferno"]["big"]["box"][3] = YAML::Load("[26, 0, 408]");
    fileNode["inferno"]["big"]["box"][4] = YAML::Load("[27, 48, 408]");
    fileNode["inferno"]["big"]["floor"][0] = YAML::Load("[2, 0, 360]");
    fileNode["inferno"]["big"]["floor"][1] = YAML::Load("[3, 48, 360]");
    fileNode["inferno"]["big"]["floor"][2] = YAML::Load("[5, 0, 408]");
    fileNode["inferno"]["big"]["floor"][3] = YAML::Load("[59, 48, 408]");
    fileNode["inferno"]["big"]["misc"][0]= YAML::Load("[71, 0, 360]");
    fileNode["inferno"]["big"]["misc"][1] = YAML::Load("[72, 0, 408]");
    fileNode["inferno"]["big"]["misc"][2] = YAML::Load("[73, 48, 360]");
    fileNode["inferno"]["big"]["misc"][3] = YAML::Load("[74, 48, 408]");
    fileNode["inferno"]["big"]["wall"][0] = YAML::Load("[39, 0, 360]");
    fileNode["inferno"]["big"]["wall"][1] = YAML::Load("[43, 48, 360]");
    fileNode["inferno"]["big"]["wall"][2] = YAML::Load("[4, 96, 360]");
    fileNode["inferno"]["big"]["wall"][3] = YAML::Load("[38, 0, 408]");
    fileNode["inferno"]["big"]["wall"][4] = YAML::Load("[44, 48, 408]");

    fileNode["dust"]["huge"]["box"][0] = YAML::Load("[21, 0, 552]");
    fileNode["dust"]["huge"]["box"][1] = YAML::Load("[22, 0, 504]");
    fileNode["dust"]["huge"]["box"][2] = YAML::Load("[23, 48, 552]");
    fileNode["dust"]["huge"]["box"][3] = YAML::Load("[24, 48, 504]");
    fileNode["dust"]["huge"]["box"][4] = YAML::Load("[25, 98, 552]");
    fileNode["dust"]["huge"]["box"][5] = YAML::Load("[26, 98, 504]");
    fileNode["dust"]["huge"]["box"][6] = YAML::Load("[27, 146, 552]");
    fileNode["dust"]["huge"]["box"][7] = YAML::Load("[28, 146, 504]");
    fileNode["dust"]["huge"]["box"][8] = YAML::Load("[29, 194, 504]");
    fileNode["dust"]["huge"]["box"][9] = YAML::Load("[30, 194, 552]");
    fileNode["dust"]["huge"]["floor"][0] = YAML::Load("[2, 0, 552]");
    fileNode["dust"]["huge"]["floor"][1] = YAML::Load("[51, 0, 504]");
    fileNode["dust"]["huge"]["floor"][2] = YAML::Load("[52, 48, 552]");
    fileNode["dust"]["huge"]["floor"][3] = YAML::Load("[53, 48, 504]");
    fileNode["dust"]["huge"]["floor"][4] = YAML::Load("[54, 98, 552]");
    fileNode["dust"]["huge"]["floor"][5] = YAML::Load("[55, 98, 504]");
    fileNode["dust"]["huge"]["floor"][6] = YAML::Load("[56, 146, 552]");
    fileNode["dust"]["huge"]["floor"][7] = YAML::Load("[57, 146, 504]");
    fileNode["dust"]["huge"]["floor"][8] = YAML::Load("[58, 194, 504]");
    fileNode["dust"]["huge"]["floor"][9] = YAML::Load("[59, 194, 552]");
    fileNode["dust"]["huge"]["floor"][10] = YAML::Load("[60, 244, 552]");
    fileNode["dust"]["huge"]["misc"][0] = YAML::Load("[61, 0, 552]");
    fileNode["dust"]["huge"]["misc"][1] = YAML::Load("[62, 48, 552]");
    fileNode["dust"]["huge"]["misc"][2] = YAML::Load("[63, 98, 552]");
    fileNode["dust"]["huge"]["misc"][3] = YAML::Load("[65, 48, 504]");
    fileNode["dust"]["huge"]["misc"][4] = YAML::Load("[70, 0, 504]");
    fileNode["dust"]["huge"]["wall"][0] = YAML::Load("[3, 0, 552]");
    fileNode["dust"]["huge"]["wall"][1] = YAML::Load("[4, 0, 504]");
    fileNode["dust"]["huge"]["wall"][2] = YAML::Load("[5, 48, 552]");
    fileNode["dust"]["huge"]["wall"][3] = YAML::Load("[38, 48, 504]");
    fileNode["dust"]["huge"]["wall"][4] = YAML::Load("[39, 98, 552]");
    fileNode["dust"]["huge"]["wall"][5] = YAML::Load("[43, 98, 504]");
    fileNode["dust"]["huge"]["wall"][6] = YAML::Load("[44, 146, 552]");

    fileNode["aztec"]["huge"]["box"][0] = YAML::Load("[21, 0, 552]");
    fileNode["aztec"]["huge"]["box"][1] = YAML::Load("[22, 48, 552]");
    fileNode["aztec"]["huge"]["box"][2] = YAML::Load("[23, 98, 552]");
    fileNode["aztec"]["huge"]["box"][3] = YAML::Load("[26, 0, 504]");
    fileNode["aztec"]["huge"]["box"][4] = YAML::Load("[27, 48, 504]");
    fileNode["aztec"]["huge"]["floor"][0] = YAML::Load("[2, 0, 552]");
    fileNode["aztec"]["huge"]["floor"][1] = YAML::Load("[3, 48, 552]");
    fileNode["aztec"]["huge"]["floor"][2] = YAML::Load("[4, 98, 552]");
    fileNode["aztec"]["huge"]["misc"][0] = YAML::Load("[38, 0, 552]");
    fileNode["aztec"]["huge"]["misc"][1] = YAML::Load("[39, 48, 552]");
    fileNode["aztec"]["huge"]["misc"][2] = YAML::Load("[43, 0, 504]");
    fileNode["aztec"]["huge"]["misc"][3] = YAML::Load("[44, 48, 504]");
    fileNode["aztec"]["huge"]["wall"][0] = YAML::Load("[7, 0, 552]");
    fileNode["aztec"]["huge"]["wall"][1] = YAML::Load("[11, 0, 504]");
    fileNode["aztec"]["huge"]["wall"][2] = YAML::Load("[8, 48, 552]");
    fileNode["aztec"]["huge"]["wall"][3] = YAML::Load("[12, 48, 504]");
    fileNode["aztec"]["huge"]["wall"][4] = YAML::Load("[9, 98, 552]");
    fileNode["aztec"]["huge"]["wall"][5] = YAML::Load("[13, 98, 504]");
    fileNode["aztec"]["huge"]["wall"][6] = YAML::Load("[14, 146, 552]");
    fileNode["aztec"]["huge"]["wall"][7] = YAML::Load("[16, 146, 504]");
    fileNode["aztec"]["huge"]["wall"][8] = YAML::Load("[17, 194, 504]");
    fileNode["aztec"]["huge"]["wall"][9] = YAML::Load("[18, 194, 552]");
    fileNode["aztec"]["huge"]["wall"][10] = YAML::Load("[19, 242, 552]");
    
    fileNode["inferno"]["huge"]["box"][0] = YAML::Load("[21, 0, 504]");
    fileNode["inferno"]["huge"]["box"][1] = YAML::Load("[22, 48, 504]");
    fileNode["inferno"]["huge"]["box"][2] = YAML::Load("[23, 96, 504]");
    fileNode["inferno"]["huge"]["box"][3] = YAML::Load("[26, 0, 552]");
    fileNode["inferno"]["huge"]["box"][4] = YAML::Load("[27, 48, 552]");
    fileNode["inferno"]["huge"]["floor"][0] = YAML::Load("[2, 0, 504]");
    fileNode["inferno"]["huge"]["floor"][1] = YAML::Load("[3, 48, 504]");
    fileNode["inferno"]["huge"]["floor"][2] = YAML::Load("[5, 0, 552]");
    fileNode["inferno"]["huge"]["floor"][3] = YAML::Load("[59, 48, 552]");
    fileNode["inferno"]["huge"]["misc"][0]= YAML::Load("[71, 0, 552]");
    fileNode["inferno"]["huge"]["misc"][1] = YAML::Load("[72, 0, 504]");
    fileNode["inferno"]["huge"]["misc"][2] = YAML::Load("[73, 48, 552]");
    fileNode["inferno"]["huge"]["misc"][3] = YAML::Load("[74, 48, 504]");
    fileNode["inferno"]["huge"]["wall"][0] = YAML::Load("[39, 0, 504]");
    fileNode["inferno"]["huge"]["wall"][1] = YAML::Load("[43, 48, 504]");
    fileNode["inferno"]["huge"]["wall"][2] = YAML::Load("[4, 96, 504]");
    fileNode["inferno"]["huge"]["wall"][3] = YAML::Load("[38, 0, 552]");
    fileNode["inferno"]["huge"]["wall"][4] = YAML::Load("[44, 48, 552]");

    fileNode["small"]["obstacles"][0] = YAML::Load("[2, 0, 360]");
    fileNode["small"]["obstacles"][1] = YAML::Load("[3, 0, 408]");
    fileNode["small"]["obstacles"][2] = YAML::Load("[4, 48, 360]");
    fileNode["small"]["obstacles"][3] = YAML::Load("[5, 48, 408]");
    fileNode["small"]["obstacles"][4] = YAML::Load("[36, 98, 360]");
    fileNode["small"]["obstacles"][5] = YAML::Load("[37, 98, 408]");

    fileNode["big"]["obstacles"][0] = YAML::Load("[2, 0, 360]");
    fileNode["big"]["obstacles"][1] = YAML::Load("[3, 0, 408]");
    fileNode["big"]["obstacles"][2] = YAML::Load("[4, 48, 360]");
    fileNode["big"]["obstacles"][3] = YAML::Load("[5, 48, 408]");
    fileNode["big"]["obstacles"][4] = YAML::Load("[36, 98, 360]");
    fileNode["big"]["obstacles"][5] = YAML::Load("[37, 98, 408]");

    fileNode["huge"]["obstacles"][0] = YAML::Load("[2, 0, 552]");
    fileNode["huge"]["obstacles"][1] = YAML::Load("[3, 0, 504]");
    fileNode["huge"]["obstacles"][2] = YAML::Load("[4, 48, 552]");
    fileNode["huge"]["obstacles"][3] = YAML::Load("[5, 48, 504]");
    fileNode["huge"]["obstacles"][4] = YAML::Load("[36, 98, 552]");
    fileNode["huge"]["obstacles"][5] = YAML::Load("[37, 98, 504]");

    file << fileNode;

    file.close();*/
}

void EditorConfig::getAtributes(std::string atributeName,const std::string& sizeName,
                                std::vector<Tile*>& options,std::vector<Tile*>& obstacleOptionsTiles,
                                const Image& image,const Image& obsImage){

    readerNode = YAML::LoadFile("editor_config.yaml");

    for(size_t i=0; i<readerNode[mapName][sizeName][atributeName].size(); i++){
        options.push_back(new Tile(readerNode[mapName][sizeName][atributeName][i][0].as<int>(),
                                   readerNode[mapName][sizeName][atributeName][i][1].as<int>(),
                                   readerNode[mapName][sizeName][atributeName][i][2].as<int>(),
                                   image));

    }
    for(size_t i=0; i<readerNode[sizeName][atributeName].size(); i++){

        obstacleOptionsTiles.push_back(new Tile(readerNode[sizeName][atributeName][i][0].as<int>(),
                                                readerNode[sizeName][atributeName][i][1].as<int>(),
                                                readerNode[sizeName][atributeName][i][2].as<int>(),
                                                obsImage));
    }
}

EditorConfig::~EditorConfig(){}
