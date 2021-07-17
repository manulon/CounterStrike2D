#ifndef _JOIN_OTHER_PLAYER_INFO_H_
#define _JOIN_OTHER_PLAYER_INFO_H_
#include "Info.h"
#include <iostream>
class JoinOtherPlayerInfo : public Info {
    private:
        short value;
	public:
		JoinOtherPlayerInfo(short value) : Info(), value(value){}
		~JoinOtherPlayerInfo(){}
		virtual void update(TileMap &map){
            map.addNewSoldier(value);
        }
};

#endif // INFO_H