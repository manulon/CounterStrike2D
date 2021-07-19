#ifndef _UPDATE_ANGLE_EVENT_H_
#define _UPDATE_ANGLE_EVENT_H_
#include "ServerEvent.h"

class UpdateAngleEvent : public ServerEvent{
    private:
		short arg;

	public:
		UpdateAngleEvent(short id, short arg);
		~UpdateAngleEvent(){}
		virtual void handle(Game &game) override;
};

#endif