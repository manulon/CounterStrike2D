#include "LifeMessage.h"


LifeMessage::LifeMessage(short value) : value(value){}

void LifeMessage::send(CommunicationProtocol &protocol){
    char command(LIFE_MESSAGE);
    protocol.send_message(&command, 1);
    protocol.send_int16(value);
}