#ifndef _QUIT_EVENT_H_
#define _QUIT_EVENT_H_
#include "ServerEvent.h"

class QuitEvent : public ServerEvent{
    public:
		QuitEvent(short id); //Para multipartida llega el nombre de la partida tambien 
		~QuitEvent();
		virtual void handle(Game &game) override;
};

#endif // _LOGIN_EVENT_H