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
 
bool Event::send(CommunicationProtocol &protocol){
    protocol.send_message(&opcode,1);                
    if ( opcode == SHOOT || opcode == ANGLE){
        protocol.send_int16((uint16_t)arg);
        return true;
    } else if (opcode == QUIT) {
        return false;
    }
    return true;
}
