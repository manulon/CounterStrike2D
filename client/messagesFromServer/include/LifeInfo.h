#ifndef LIFE_INFO_H_
#define LIFE_INFO_H_
#include "Info.h"
#include <iostream>
class LifeInfo : public Info {
    private:
        short value;
	public:
		LifeInfo(short value) : Info(), value(value){}
		~LifeInfo(){}
		virtual void update(TileMap &map){
            map.setPrincipalPlayerLife(value);
        }
};

#endif // INFO_H