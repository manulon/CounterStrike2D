#ifndef _END_OF_GAME_INFO_H_
#define _END_OF_GAME_INFO_H_
#include "Info.h"
#include "GameEndedException.h"
#include <iostream>

class EndOfGameInfo : public Info {
    private:
        std::string message;
	public:
		EndOfGameInfo(std::string &&message) : Info(), message(message) {}
		~EndOfGameInfo(){}
		virtual void update(TileMap &map){
            map.printResult(message);
            throw GameEndedException();
        }
};

#endif // INFO_H