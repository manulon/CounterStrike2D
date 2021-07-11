#ifndef _CLIENT_PROTOCOL_H_
#define _CLIENT_PROTOCOL_H_

#include "../common/CommunicationProtocol.h"
#include "../common/ProtocolConstants.h"

class ClientProtocol{
    private:
        ClientProtocol(const ClientProtocol& other) = delete;
        ClientProtocol& operator=(const ClientProtocol& other) = delete;

        //CommunicationProtocol protocol;

    public:
        ClientProtocol();
        ~ClientProtocol();

        void moveLeft();
        void moveRight();
        void moveDown();
        void moveUp();
        void stopMoveLeft();
        void stopMoveRight();
        void stopMoveDown();
        void stopMoveUp();
        void quit();
        void mouseDown();
};

#endif