#ifndef _STOP_PICKING_UP_WEAPON_EVENT_H_
#define _STOP_PICKING_UP_WEAPON_EVENT_H_
#include "ServerEvent.h"

class StopPickingUpWeaponEvent : public ServerEvent{
    public:
		StopPickingUpWeaponEvent(short id);
		~StopPickingUpWeaponEvent(){}
		virtual void handle(Game &game) override;
};

#endif // _LOGIN_EVENT_H