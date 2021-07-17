#ifndef _GAME_OPTION_EXIT_H_
#define _GAME_OPTION_EXIT_H_

#include "GameOption.h"

class GameOptionExit: public GameOption{
    private:
        GameOptionExit(const GameOptionExit& other) = delete;
        GameOptionExit& operator=(const GameOptionExit& other) = delete;

    public:
        GameOptionExit(Window &window);
        ~GameOptionExit();

        virtual bool clicked(std::vector<GameOption*>& options);
        virtual void setPath(std::string& path,std::string& tiles) override;
};

#endif