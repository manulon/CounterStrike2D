#ifndef PLAYER_INFO_H_
#define PLAYER_INFO_H_
#include "Info.h"
#include <iostream>
class PlayerInfo : public Info {
    private:
        short id;
        float x;
        float y;
        short weaponId;
        short angle;
	public:
		PlayerInfo( short id, float x, float y, short weaponId,short angle) : 
        Info(), id(id), x(x),y(y), weaponId(weaponId), angle(angle){}
		~PlayerInfo(){}
		virtual void update(TileMap &map){
            map.updateSoldierInfo(id, x, y, weaponId,angle);
        }
};

#endif // INFO_H