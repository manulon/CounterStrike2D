#include "Life.h"
#include <iostream>

Life::Life(): 
/*deberia ser value(0)*/value(100){
    //getInitialValue();
}

void Life::decreaseLife(int valueToDecrease){
    if ( (value -= valueToDecrease) < 0){
        std::cout<<"El jugador ha muerto"<<std::endl;
        value = 0;
    }
    std::cout<<"La vida del jugador es "<<value<<std::endl;
}

int Life::getLife(){
    return value;
}

Life::~Life(){}
