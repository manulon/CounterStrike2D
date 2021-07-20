#ifndef _SWITCH_WEAPON_EVENT_H_
#define _SWITCH_WEAPON_EVENT_H_
#include "ServerEvent.h"

class SwitchWeaponEvent : public ServerEvent{
    private:
        char weapon;
    public:
		SwitchWeaponEvent(short id, char weapon);
		~SwitchWeaponEvent(){}
		virtual void handle(Game &game) override;
};

#endif // _LOGIN_EVENT_H