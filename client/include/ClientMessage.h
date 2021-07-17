#ifndef _CLIENT_MESSAGE_
#define _CLIENT_MESSAGE_
#include "CommunicationProtocol.h"
class ClientMessage {    
    private:
        ClientMessage(const ClientMessage &other) = delete;
        ClientMessage& operator=(const ClientMessage &other) = delete;
    public:
        ClientMessage();
        virtual ~ClientMessage();
        ClientMessage(ClientMessage&& other);

        /*
         * @return: devuelve false si el evente significa que termina el juego
         */
        virtual bool send(CommunicationProtocol &protocol);
};

#endif