#include "Life.h"
#include <iostream>

Life::Life(): 
/*deberia ser value(0)*/value(100){
    //getInitialValue();
}

void Life::decreaseLife(int valueToDecrease){
    if ( (value -= valueToDecrease) < 0){
        value = 0;
    }
}

int Life::getLife(){
    return value;
}

Life::~Life(){}
