#include "Event.h"

Event::Event(int id, char opcode, int arg):
id(id),opcode(opcode),arg(arg){}

int  Event::getId(){
    return id;
}

char Event:: getOpcode(){
    return opcode;
}

int Event::getArg(){
    return arg;
}
