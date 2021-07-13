#ifndef _GAME_OPTION_H_
#define _GAME_OPTION_H_

#include "Image.h"
#include "Area.h"
#include <iostream>
#include <vector>

class GameOption{
    private:
        GameOption(const GameOption& other) = delete;
        GameOption& operator=(const GameOption& other) = delete;

    protected:
        Image button;
        Area buttonArea;

    public:
        GameOption(const char *path,Window &window,
                   int x, int y, int w, int h);
        virtual ~GameOption();

        void render();
        bool mouseInButton(int x, int y);
        virtual bool clicked(std::vector<GameOption*>& options) = 0;
        virtual void setPath(std::string& path,std::string& tiles) = 0;

};

#endif