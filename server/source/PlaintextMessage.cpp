#include "PlaintextMessage.h"
#include <iostream>
PlaintextMessage::PlaintextMessage(std::string msg) : msg(msg){}

PlaintextMessage::PlaintextMessage(PlaintextMessage&& other) : ServerMessage(std::move(other)), msg(std::move(other.msg)){}

void PlaintextMessage::send(CommunicationProtocol &protocol){
    std::cout << "ENVIANDO PLAINTEXT\n";
    char message = TEXT_MESSAGE;
    protocol.send_message(&message,1);
    std::cout <<"code enviado\n";
    protocol.send_int16(msg.length());
    std::cout <<"len enviado\n";
    protocol.send_message(msg.c_str(),msg.length());
    std::cout <<"ENVIANDO PLAINTEXT TERMINADO \n";

}