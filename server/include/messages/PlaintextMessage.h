#ifndef _PLAINTEXT_MESSAGE_
#define _PLAINTEXT_MESSAGE_
#include <string>
#include "ServerMessage.h"
class PlaintextMessage : public ServerMessage{    
    private:
        std::string msg;
        PlaintextMessage(const PlaintextMessage &other) = delete;
    public:
        PlaintextMessage(std::string msg);
        PlaintextMessage(PlaintextMessage&& other);
        ~PlaintextMessage(){}
        virtual void send(CommunicationProtocol &protocol) override;
};

#endif