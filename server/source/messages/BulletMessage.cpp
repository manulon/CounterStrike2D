#include "BulletMessage.h"


BulletMessage::BulletMessage(short int posX, short int posY): 
posX(posX),posY(posY){}

void BulletMessage::send(CommunicationProtocol &protocol){
    char command(BULLET_MESSAGE);
    protocol.send_message(&command, 1);
    protocol.send_int16(posX);
    protocol.send_int16(posY);
}