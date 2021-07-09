#include "ClientProtocol.h"

ClientProtocol::ClientProtocol():
protocol(){}

ClientProtocol::~ClientProtocol(){}

void ClientProtocol::moveLeft(){
    char key(KEYWORD_SCANDODE_LEFT);

    this->protocol.send_message(&key,1);
}

void ClientProtocol::moveRight(){
    char key(KEYWORD_SCANDODE_RIGHT);

    this->protocol.send_message(&key,1);
}

void ClientProtocol::moveDown(){
    char key(KEYWORD_SCANDODE_DOWN);

    this->protocol.send_message(&key,1);
}

void ClientProtocol::moveUp(){
    char key(KEYWORD_SCANDODE_UP);

    this->protocol.send_message(&key,1);
}

void ClientProtocol::stopMoveLeft(){
    char key(KEYWORD_KEYUP_LEFT);

    this->protocol.send_message(&key,1);
}

void ClientProtocol::stopMoveRight(){
    char key(KEYWORD_KEYUP_RIGHT);

    this->protocol.send_message(&key,1);
}

void ClientProtocol::stopMoveDown(){
    char key(KEYWORD_KEYUP_DOWN);

    this->protocol.send_message(&key,1);
}

void ClientProtocol::stopMoveUp(){
    char key(KEYWORD_KEYUP_UP);

    this->protocol.send_message(&key,1);
}

void ClientProtocol::quit(){
    char key(QUIT);

    this->protocol.send_message(&key,1);
}

void ClientProtocol::mouseDown(){
    char key(MOUSE_DOWN);

    this->protocol.send_message(&key,1);
}
