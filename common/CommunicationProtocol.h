#ifndef COMMUNICATION_PROTOCOL_H
#define COMMUNICATION_PROTOCOL_H

#include "Socket.h"
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include "ProtocolConstants.h"

class CommunicationProtocol{
    Socket& socket;

public:
    ~CommunicationProtocol(){}
    explicit CommunicationProtocol(Socket&socket);   
    
    //Delega el envio del mensaje recibido por parametro al socket.
    void send_message(const char* msg,int length);
    
    //Delega el envio del size recibido por parametro al socket.
    void send_int16(uint16_t size);
    
    //Delega la recepcion de un mensaje de largo length al socket.
    ssize_t receive_message(int length, char* buffer);
    
    //Delega la recepcion del tamaño de un mensaje al socket.
    int receive_size();

    void send_float(float value);

    float receive_float();
};

#endif
