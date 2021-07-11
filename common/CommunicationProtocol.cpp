#include "CommunicationProtocol.h"
#include <iostream>
#include <arpa/inet.h>


CommunicationProtocol:: CommunicationProtocol(Socket& socket):
socket(socket){}

void CommunicationProtocol:: send_message(const char* msg,int length){
    this->socket.send(msg,length);
}

void CommunicationProtocol:: send_int16(uint16_t size){
    size = htons(size);
    this->socket.send((char*)&size,2);
}

ssize_t CommunicationProtocol:: receive_message
(int length, char* buffer){
    return this->socket.receive(buffer,length);
}

int CommunicationProtocol:: receive_size(){
    uint16_t size(0);
    this->socket.receive((char*)&size,2);
    return (int)ntohs(size);
}

CommunicationProtocol:: ~CommunicationProtocol(){}
