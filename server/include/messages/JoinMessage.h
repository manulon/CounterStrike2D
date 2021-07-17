#ifndef _JOIN_MESSAGE_H_
#define _JOIN_MESSAGE_H_
#include "ServerMessage.h"

class JoinMessage : public ServerMessage {    
    public:
        JoinMessage(short value);
        virtual ~JoinMessage(){}
        virtual void send(CommunicationProtocol &protocol) override;
    private:
        short value;
};

#endif