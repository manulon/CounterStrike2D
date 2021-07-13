#ifndef _GAME_OPTION_SELECT_MODE_H_
#define _GAME_OPTION_SELECT_MODE_H_

#include "GameOption.h"
#include "GameOptionDust.h"
#include "GameOptionAztec.h"
#include "GameOptionInferno.h"
#include "GameOptionPlayer.h"

class GameOptionSelectMode: public GameOption{
    private:
        GameOptionSelectMode(const GameOptionSelectMode& other) = delete;
        GameOptionSelectMode& operator=(const GameOptionSelectMode& other) = delete;

        Window& window;

    public:
        GameOptionSelectMode(Window &window);
        ~GameOptionSelectMode();

        virtual bool clicked(std::vector<GameOption*>& options);
        virtual void setPath(std::string& path,std::string& tiles) override;
};

#endif