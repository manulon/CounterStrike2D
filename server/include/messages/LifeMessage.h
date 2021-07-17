#ifndef _LIFE_MESSAGE_H_
#define _LIFE_MESSAGE_H_
#include "ServerMessage.h"

class LifeMessage : public ServerMessage {    
    public:
        LifeMessage(short value);
        virtual ~LifeMessage(){}
        virtual void send(CommunicationProtocol &protocol) override;
    private:
        short value;
};

#endif