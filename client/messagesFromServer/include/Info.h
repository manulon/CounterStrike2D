#ifndef _INFO_H_
#define _INFO_H_
//#include "TileMap.h"
class Info {

	public:
		Info(){}
		~Info(){}
		virtual void update(/*TileMap &map*/) = 0;
};

#endif // INFO_H