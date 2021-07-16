#include "PlaintextMessage.h"
#include <iostream>
PlaintextMessage::PlaintextMessage(std::string msg) : msg(msg){}

PlaintextMessage::PlaintextMessage(PlaintextMessage&& other) : ServerMessage(std::move(other)), msg(std::move(other.msg)){}

void PlaintextMessage::send(CommunicationProtocol &protocol){
    char message = TEXT_MESSAGE;
    protocol.send_message(&message,1);
    protocol.send_int16(msg.length());
    protocol.send_message(msg.c_str(),msg.length());

}