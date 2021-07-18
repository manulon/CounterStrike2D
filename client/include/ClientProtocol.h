#ifndef _CLIENT_PROTOCOL_H_
#define _CLIENT_PROTOCOL_H_

#include "CommunicationProtocol.h"
#include "ProtocolConstants.h"
#include "BlockingQueue.h"
#include "Event.h"
#include "LoginMessage.h"

class ClientProtocol{
    private:
        ClientProtocol(const ClientProtocol& other) = delete;
        ClientProtocol& operator=(const ClientProtocol& other) = delete;

        BlockingQueue<std::shared_ptr<ClientMessage>>& queue;
        

    public:
        ClientProtocol(BlockingQueue<std::shared_ptr<ClientMessage>>& queue);
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
        void attack(short angle);
        void list();
};

#endif