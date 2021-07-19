#ifndef _PICK_UP_WEAPON_EVENT_H_
#define _PICK_UP_WEAPON_EVENT_H_
#include "ServerEvent.h"

class PickUpWeaponEvent : public ServerEvent{
    public:
		PickUpWeaponEvent(short id);
		~PickUpWeaponEvent(){}
		virtual void handle(Game &game) override;
};

#endif // _LOGIN_EVENT_H