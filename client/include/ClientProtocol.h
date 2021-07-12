#ifndef _CLIENT_PROTOCOL_H_
#define _CLIENT_PROTOCOL_H_

#include "../common/CommunicationProtocol.h"
#include "../common/ProtocolConstants.h"
#include "BlockingQueue.h"
#include "Event.h"

class ClientProtocol{
    private:
        ClientProtocol(const ClientProtocol& other) = delete;
        ClientProtocol& operator=(const ClientProtocol& other) = delete;
        CommunicationProtocol protocol;

        BlockingQueue<std::shared_ptr<Event>>& queue;
        

    public:
        ClientProtocol(Socket &skt, BlockingQueue<std::shared_ptr<Event>>& queue);
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
        void attack();
};

#endif