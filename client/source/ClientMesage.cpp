#include "ClientMessage.h"

ClientMessage::ClientMessage(){}

ClientMessage::~ClientMessage(){}
        
ClientMessage::ClientMessage(ClientMessage&& other){}
        
bool ClientMessage::send(CommunicationProtocol &protocol){//overrideable
    return true;
}