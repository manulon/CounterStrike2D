#ifndef _EVENT_
#define _EVENT_
#include "ClientMessage.h"
class Event : public ClientMessage {
    private:
        int id;
        char opcode;
        int arg;
    
    public:
        Event(int id, char opcode, int arg);
        ~Event(){}
        
        int getId();
        char getOpcode();
        int getArg();
        virtual bool send(CommunicationProtocol &protocol) override;
};

#endif