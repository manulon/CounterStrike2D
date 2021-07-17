#ifndef _OTHER_PLAYER_JOINED_MESSAGE_H_
#define _OTHER_PLAYER_JOINED_MESSAGE_H_
#include "ServerMessage.h"

class OtherPlayerJoinedMessage : public ServerMessage {    
    public:
        OtherPlayerJoinedMessage(short value);
        virtual ~OtherPlayerJoinedMessage(){}
        virtual void send(CommunicationProtocol &protocol) override;
    private:
        short value;
};

#endif