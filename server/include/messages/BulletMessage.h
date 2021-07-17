#ifndef _BULLET_MESSAGE_H_
#define _BULLET_MESSAGE_H_

#include "ServerMessage.h"

class BulletMessage : public ServerMessage {    
    public:
        BulletMessage(short int posX, short int posY);
        virtual ~BulletMessage(){}
        virtual void send(CommunicationProtocol &protocol) override;
    private:
        short int posX;
        short int posY;
};

#endif