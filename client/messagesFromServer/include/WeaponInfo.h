#ifndef _WEAPON_INFO_H_
#define _WEAPON_INFO_H_
#include "Info.h"
#include <iostream>
class WeaponInfo : public Info {
    private:
        short weaponId;
        float x;
        float y;
	public:
		WeaponInfo(short id, float x, float y) : Info(), weaponId(id), x(x),y(y){}
		~WeaponInfo(){}
		virtual void update(TileMap &map){
            map.updateWeaponInfo(weaponId, x, y);
        }
};

#endif // INFO_H