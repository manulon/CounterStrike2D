#ifndef _BULLET_MESSAGE_H_
#define _BULLET_MESSAGE_H_

#include "ServerMessage.h"

class BulletMessage : public ServerMessage {    
    public:
        BulletMessage(float posX, float posY);
        virtual ~BulletMessage(){}
        virtual void send(CommunicationProtocol &protocol) override;
    private:
        float posX;
        float posY;
};

#endif