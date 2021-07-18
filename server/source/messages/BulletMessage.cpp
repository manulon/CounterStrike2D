#include "BulletMessage.h"


BulletMessage::BulletMessage(float posX, float posY): 
posX(posX),posY(posY){}

void BulletMessage::send(CommunicationProtocol &protocol){
    char command(BULLET_MESSAGE);
    protocol.send_message(&command, 1);
    protocol.send_float(posX);
    protocol.send_float(posY);
}