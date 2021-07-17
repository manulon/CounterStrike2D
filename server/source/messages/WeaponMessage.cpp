#include "WeaponMessage.h"


WeaponMessage::WeaponMessage(short id, short posX, short posY): 
id(id),posX(posX),posY(posY){}

void WeaponMessage::send(CommunicationProtocol &protocol){
    char command(WEAPON_MESSAGE);
    protocol.send_message(&command, 1);
    protocol.send_int16(id);
    protocol.send_int16(posX);
    protocol.send_int16(posY);
}