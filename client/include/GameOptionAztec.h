#ifndef _GAME_OPTION_AZTEC_H_
#define _GAME_OPTION_AZTEC_H_

#include "GameOption.h"

class GameOptionAztec: public GameOption{
    private:
        GameOptionAztec(const GameOptionAztec& other) = delete;
        GameOptionAztec& operator=(const GameOptionAztec& other) = delete;

    public:
        GameOptionAztec(Window &window);
        ~GameOptionAztec();

        virtual bool clicked(std::vector<GameOption*>& options);
        virtual void setPath(std::string& path,std::string& tiles) override;

};

#endif
