#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "Area.h"
#include "Tile.h"
#include "EditorConfig.h"
#include "Image.h"
#include <vector>

class Button{
    private:
        Button(const Button &other) = delete;
        Button& operator=(const Button &other) = delete;
        Button& operator=(Button &&other) = delete;

    protected:
        Image button;
        Area buttonArea;
        EditorConfig& editor;

    public:
        Button(const char *path,Window &window,EditorConfig& editor,
               int x, int y, int w, int h);
        virtual ~Button();

        bool mouseInText(int x, int y);
        virtual void render() = 0;
        virtual bool clicked(std::vector<Tile*>& options,std::vector<Tile*>& obstaclesOptionTiles,
                             std::vector<Tile*>& soldierOptionsTiles, const Image& image, 
                             const Image& obsImage, const std::string& sizeName,
                             const Image& tImage,const Image& ctImage) = 0;

};

#endif