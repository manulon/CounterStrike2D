#include "OtherPlayerJoinedMessage.h"


OtherPlayerJoinedMessage::OtherPlayerJoinedMessage(short value) : value(value){}

void OtherPlayerJoinedMessage::send(CommunicationProtocol &protocol){
    char command(OTHER_PLAYER_JOIN);
    protocol.send_message(&command, 1);
    protocol.send_int16(value);
}