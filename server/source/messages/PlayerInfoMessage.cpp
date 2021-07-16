#include "PlayerInfoMessage.h"


PlayerInfoMessage::PlayerInfoMessage(short id, float x, float y,
                                     short weaponId) : ServerMessage(), id(id), x(x),y(y),
                                     weaponId(weaponId){}

void PlayerInfoMessage::send(CommunicationProtocol &protocol){
    char command(PLAYER_INFO);
    protocol.send_message(&command, 1);
    protocol.send_int16(id);
    protocol.send_float(x);
    protocol.send_float(y);
    protocol.send_float(weaponId);    
}