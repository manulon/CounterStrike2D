#ifndef _PLAYER_INFO_H_
#define _PLAYER_INFO_H_
#include "Info.h"
#include <iostream>
class DeadPlayerInfo : public Info {
    private:
        short playerID;
	public:
		DeadPlayerInfo(short playerID) : Info(), playerID(playerID) {}
		~DeadPlayerInfo(){}
		virtual void update(TileMap &map){
            map.removePlayer(playerID);
        }
};

#endif // INFO_H