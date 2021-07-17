#include "JoinMessage.h"


JoinMessage::JoinMessage(short value) : value(value){}

void JoinMessage::send(CommunicationProtocol &protocol){
    char command(JOIN);
    protocol.send_message(&command, 1);
    protocol.send_int16(value);
}