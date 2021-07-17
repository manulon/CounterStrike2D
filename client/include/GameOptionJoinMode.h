#ifndef _GAME_OPTION_JOIN_MODE_H_
#define _GAME_OPTION_JOIN_MODE_H_

#include "GameOption.h"
#include "GameOptionDust.h"
#include "GameOptionAztec.h"
#include "GameOptionInferno.h"
#include "GameOptionPlayer.h"

class GameOptionJoinMode: public GameOption{
    private:
        GameOptionJoinMode(const GameOptionJoinMode& other) = delete;
        GameOptionJoinMode& operator=(const GameOptionJoinMode& other) = delete;

        Window& window;

    public:
        GameOptionJoinMode(Window &window);
        ~GameOptionJoinMode();

        virtual bool clicked(std::vector<GameOption*>& options);
        virtual void setPath(std::string& path,std::string& tiles) override;
};

#endif