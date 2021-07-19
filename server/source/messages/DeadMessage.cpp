#include "DeadMessage.h"


DeadMessage::DeadMessage(short playerID) : playerID(playerID) {}

void DeadMessage::send(CommunicationProtocol &protocol){
    char command(DEAD_PLAYER);
    protocol.send_message(&command, 1);
    protocol.send_int16(playerID);
}