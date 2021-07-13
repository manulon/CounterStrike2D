#ifndef _GAME_OPTION_DUST_H_
#define _GAME_OPTION_DUST_H_

#include "GameOption.h"

class GameOptionDust: public GameOption{
    private:
        GameOptionDust(const GameOptionDust& other) = delete;
        GameOptionDust& operator=(const GameOptionDust& other) = delete;

    public:
        GameOptionDust(Window &window);
        ~GameOptionDust();

        virtual bool clicked(std::vector<GameOption*>& options);
        virtual void setPath(std::string& path,std::string& tiles) override;
};

#endif
