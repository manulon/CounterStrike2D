#ifndef _BULLET_INFO_H_
#define _BULLET_INFO_H_
#include "Info.h"
#include <iostream>
class BulletInfo : public Info {
    private:
        float x,y;
	public:
		BulletInfo(float x, float y) : Info(), x(x), y(y){}
		~BulletInfo(){}
		virtual void update(TileMap &map){
            map.addNewBullet(x,y);
        }
};

#endif // INFO_H