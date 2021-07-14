#ifndef _SERVER_MESSAGE_
#define _SERVER_MESSAGE_
#include "CommunicationProtocol.h"
class ServerMessage {    
    private:
        ServerMessage(const ServerMessage &other) = delete;
        ServerMessage& operator=(const ServerMessage &other) = delete;
    public:
        ServerMessage();
        virtual ~ServerMessage();
        ServerMessage(ServerMessage&& other);
        virtual void send(CommunicationProtocol &protocol);
};

#endif