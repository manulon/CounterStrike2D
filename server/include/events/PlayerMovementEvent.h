#ifndef _PLAYER_MOVEMENT_EVENT_H_
#define _PLAYER_MOVEMENT_EVENT_H_
#include "ServerEvent.h"
class PlayerMovementEvent : public ServerEvent{
	private:
		char opcode;		
	public:
		PlayerMovementEvent(short id, char opcode); 
		~PlayerMovementEvent(){}
		virtual void handle(Game &game) override;
};

#endif // _SERVER_EVENT_H_