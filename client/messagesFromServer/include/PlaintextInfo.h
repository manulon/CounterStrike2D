#ifndef PLAINTEXT_INFO_H_
#define PLAINTEXT_INFO_H_
#include "Info.h"
#include <iostream>
class PlaintextInfo : public Info {
    private:
        std::string plaintext;
	public:
		PlaintextInfo(std::string &&value) : Info(), plaintext(value){}
		~PlaintextInfo(){}
		virtual void update(TileMap &map){
            map.printResult(plaintext);
        }
};

#endif // INFO_H