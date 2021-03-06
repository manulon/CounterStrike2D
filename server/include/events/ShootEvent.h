#ifndef SHOOT_EVENT_H_
#define SHOOT_EVENT_H_
#include "ServerEvent.h"

class ShootEvent : public ServerEvent{
	private:
        short angle;
    public:
		ShootEvent(short id, short angle); //Para multipartida llega el nombre de la partida tambien 
		~ShootEvent(){}
		virtual void handle(Game &game) override;
};

#endif // _LOGIN_EVENT_H