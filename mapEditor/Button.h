#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "SdlColor.h"
#include "Text.h"
#include "Tile.h"
#include <vector>

class Button{
    private:
        Button(const Button &other) = delete;
        Button& operator=(const Button &other) = delete;
        Button& operator=(Button &&other) = delete;

        SdlColor color;

    protected:
        Text textBox;

    public:
        Button(const char *fontPath, int ptsize,
		       const char *textToRender,Window &window);
        virtual ~Button();

        bool mouseInText(int x, int y);
        virtual void render() = 0;
        virtual bool clicked(std::vector<Tile*>& options,const Image& image) = 0;

};

#endif