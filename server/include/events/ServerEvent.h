#ifndef _SERVER_EVENT_H_
#define _SERVER_EVENT_H_
#include "Game.h"

class ServerEvent {
	protected:
		short id;

	public:
		ServerEvent(short id); //GameContainer deberia ser
		~ServerEvent();
		virtual void handle(Game &game) = 0;
};

#endif // _SERVER_EVENT_H_