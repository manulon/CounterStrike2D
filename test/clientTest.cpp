#include <iostream>
#include <Client.h>

int main(int argc, char const *argv[]){
    Client cli;
    cli.run("localhost","8080");
    return 0;
}
