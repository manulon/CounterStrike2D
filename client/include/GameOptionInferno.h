#ifndef _GAME_OPTION_INFERNO_H_
#define _GAME_OPTION_INFERNO_H_

#include "GameOption.h"

class GameOptionInferno: public GameOption{
    private:
        GameOptionInferno(const GameOptionInferno& other) = delete;
        GameOptionInferno& operator=(const GameOptionInferno& other) = delete;

    public:
        GameOptionInferno(Window &window);
        ~GameOptionInferno();

        virtual bool clicked(std::vector<GameOption*>& options);
        virtual void setPath(std::string& path,std::string& tiles) override;
};

#endif