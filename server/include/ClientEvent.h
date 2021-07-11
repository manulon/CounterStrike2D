#ifndef __CLIENT_EVENT_
#define __CLIENT_EVENT_

class ClientEvent{
    private:
        int id;
        char opcode;
        int arg;
    public:
        ClientEvent(int id, char opcode, int arg) : 
        id(id), opcode(opcode), arg(arg){}
        int getId() { return id; }
        char getOpcode() { return opcode; }
        int getArg() { return arg; }
};

#endif