#ifndef _WEAPON_MESSAGE_H_
#define _WEAPON_MESSAGE_H_

#include "ServerMessage.h"

class WeaponMessage : public ServerMessage {    
    public:
        WeaponMessage(short id, short posX, short posY);
        virtual ~WeaponMessage(){}
        virtual void send(CommunicationProtocol &protocol) override;
    private:
        short id;
        short posX;
        short posY;
};

#endif