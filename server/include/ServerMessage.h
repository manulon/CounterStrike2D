#ifndef _SERVER_MESSAGE_
#define _SERVER_MESSAGE_
#include "CommunicationProtocol.h"
class ServerMessage {    
    public:
        ServerMessage(){}
        virtual void send(CommunicationProtocol &protocol) = 0;
};

#endif