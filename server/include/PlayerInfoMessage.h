#ifndef _PLAYER_INFO_MESSAGE_H_
#define _PLAYER_INFO_MESSAGE_H_
#include "ServerMessage.h"

class PlayerInfoMessage : public ServerMessage {    
    public:
        PlayerInfoMessage(short id, float x, float y,
                          short weaponId);
        virtual void send(CommunicationProtocol &protocol) override;
    private:
        short id;
        float x; 
        float y;
        short weaponId;
};

#endif