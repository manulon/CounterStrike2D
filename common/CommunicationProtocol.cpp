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
    this->socket.send((char*)&size,sizeof(size));
}


void CommunicationProtocol::send_float(float value){
    int enlarged_float = htonl(value*1000);
    this->socket.send((char*)&enlarged_float,sizeof(enlarged_float));
}

float CommunicationProtocol::receive_float(){
    int num(0);
    this->socket.receive((char*)&num,sizeof(num));
    num = ntohl(num);
    float aux = ((float)num)/1000.0f;
    return aux;
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
