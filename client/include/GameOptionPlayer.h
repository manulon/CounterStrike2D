#ifndef _GAME_OPTION_PLAYER_H_
#define _GAME_OPTION_PLAYER_H_

#include "GameOption.h"
#include "yaml-cpp/yaml.h"

class GameOptionPlayer: public GameOption{
    private:
        GameOptionPlayer(const GameOptionPlayer& other) = delete;
        GameOptionPlayer& operator=(const GameOptionPlayer& other) = delete;

    public:
        GameOptionPlayer(Window &window);
        ~GameOptionPlayer();

        virtual bool clicked(std::vector<GameOption*>& options);
        virtual void setPath(std::string& path,std::string& tiles) override;
};

#endif