#ifndef JOIN_INFO_H_
#define JOIN_INFO_H_
#include "Info.h"
#include <iostream>
class JoinInfo : public Info {
    private:
        short value;
	public:
		JoinInfo(short value) : Info(), value(value){}
		~JoinInfo(){}
		virtual void update(TileMap &map){
            std::cout<<"el principal player tiene id "<<value<<std::endl;
            map.setPrincipalPlayerId(value);
        }
};

#endif // INFO_H