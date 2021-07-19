#include "LoginMessage.h"

LoginMessage::LoginMessage(char opcode, std::string buffer) : opcode(opcode), buffer(buffer){} 

bool LoginMessage::send(CommunicationProtocol &protocol){
    protocol.send_message(&opcode, 1);
    protocol.send_int16((u_int16_t) buffer.length()); // esto es para cuando haya multiples partidas
    protocol.send_message(buffer.c_str(), buffer.length());
    return true;
}