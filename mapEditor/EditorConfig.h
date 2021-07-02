#ifndef _EDITOR_CONFIG_H_
#define _EDITOR_CONFIG_H_

#include "yaml-cpp/yaml.h"
#include "Tile.h"
#include <iostream>
#include <fstream>
#include <string>

#define BOX 1
#define FLOOR 2
#define MISC 3
#define WALL 4

class EditorConfig{
    private:
        EditorConfig(const EditorConfig &other) = delete;
        EditorConfig& operator=(const EditorConfig &other) = delete;
        EditorConfig& operator=(EditorConfig &&other) = delete;

        void createFile();
        int getAtributeNumber(const std::string& name);

        YAML::Node fileNode;
        YAML::Node readerNode;
        const char* mapName;

    public:
        EditorConfig(const char* mapName);
        ~EditorConfig();

        void getAtributes(std::string atributeName, 
                          std::vector<Tile*>& options,const Image& image);
};

#endif