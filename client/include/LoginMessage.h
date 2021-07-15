#ifndef _LOGIN_MESSAGE_
#define _LOGIN_MESSAGE_
#include "ClientMessage.h"
#include <string>
class LoginMessage : public ClientMessage {
    private:
        char opcode;
        std::string buffer;
    
    public:
        LoginMessage(char opcode, const std::string buffer);
        ~LoginMessage(){}
        
        virtual bool send(CommunicationProtocol &protocol) override;
};

#endif