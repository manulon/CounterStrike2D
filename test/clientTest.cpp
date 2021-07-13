#include <iostream>
#include "Client.h"
#include "Window.h"

int main(int argc, char const *argv[]){
    Window window("Counter Strike 2D", 800, 600, 
                  SDL_WINDOW_RESIZABLE, 
                  SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    Client cli;
    cli.run("localhost","8080");
    return 0;
}
