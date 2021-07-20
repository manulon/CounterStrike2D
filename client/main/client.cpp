#include <iostream>
#include "Client.h"
#include "Window.h"

int main(int argc, char const *argv[]){
    Client cli;
    cli.run(argv[1],argv[2]);
    return 0;
}
