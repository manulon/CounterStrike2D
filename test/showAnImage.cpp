#include "Window.h"
#include "Image.h"
#include "Area.h"
#include "Stencil.h"
#include <SDL2/SDL.h>
#include <exception>
#include <iostream>
#include <unistd.h>

int main(int argc, const char *argv[]){
    try {
        Window window("Counter Strike 2D", 800, 600, SDL_WINDOW_RESIZABLE);
        Image image("assets/gfx/backgrounds/toxic.jpg", window);
        Stencil stencil(1000, 1000, 25, 90, 150, window); 
        Area imageArea(0, 0, 800, 600);
        Area stencilArea((800/2)-(1000/2), (600/2)-(1000/2), 1000, 1000);
        image.render(imageArea);
        stencil.render(stencilArea, 0);
        window.render();
        usleep(3000000);

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
