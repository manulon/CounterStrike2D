#ifndef _EVENT_
#define _EVENT_

class Event{
    private:
        int id;
        char opcode;
        int arg;
    
    public:
        Event(int id, char opcode, int arg);
        ~Event();
        
        int getId();
        char getOpcode();
        int getArg();
};

#endif