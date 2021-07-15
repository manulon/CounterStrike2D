#ifndef _LOGIN_EVENT_H_
#define _LOGIN_EVENT_H_
#include "ServerEvent.h"
class LoginEvent : public ServerEvent{
	public:
		LoginEvent(short id); //Para multipartida llega el nombre de la partida tambien 
		~LoginEvent();
		virtual void handle(Game &game) override;
};

#endif // _LOGIN_EVENT_H