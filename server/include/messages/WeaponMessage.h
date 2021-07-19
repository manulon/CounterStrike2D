#ifndef _WEAPON_MESSAGE_H_
#define _WEAPON_MESSAGE_H_

#include "ServerMessage.h"

class WeaponMessage : public ServerMessage {    
    private:
        short id;
        float posX;
        float posY;
    public:
        WeaponMessage(short id, float posX, float posY);
        virtual ~WeaponMessage(){}
        virtual void send(CommunicationProtocol &protocol) override;
};

#endif