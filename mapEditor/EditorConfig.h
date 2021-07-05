#ifndef _EDITOR_CONFIG_H_
#define _EDITOR_CONFIG_H_

#include "yaml-cpp/yaml.h"
#include "Tile.h"
#include <iostream>
#include <fstream>
#include <string>


class EditorConfig{
    private:
        EditorConfig(const EditorConfig &other) = delete;
        EditorConfig& operator=(const EditorConfig &other) = delete;
        EditorConfig& operator=(EditorConfig &&other) = delete;

        void createFile();

        YAML::Node fileNode;
        YAML::Node readerNode;
        const char* mapName;

    public:
        EditorConfig(const char* mapName);
        ~EditorConfig();

        void getAtributes(std::string atributeName,const std::string& sizeName, 
                          std::vector<Tile*>& options,std::vector<Tile*>& obstacleOptionsTiles,
                          const Image& image, const Image& obsImage);
};

#endif