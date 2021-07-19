#ifndef _DEAD_MESSAGE_H_
#define _DEAD_MESSAGE_H_
#include "ServerMessage.h"

class DeadMessage : public ServerMessage {    
    public:
        DeadMessage(short playerID);
        virtual ~DeadMessage(){}
        virtual void send(CommunicationProtocol &protocol) override;
    private:
        short playerID;
};

#endif