#include "Window.h"
#include "Image.h"
#include "Area.h"
#include <SDL2/SDL.h>
#include <exception>
#include <iostream>
#include <unistd.h>

int main(int argc, const char *argv[]){
    try {
        Window window("Ventana de prueba", 800, 600, SDL_WINDOW_RESIZABLE);
        Image image("assets/gfx/backgrounds/toxic.jpg", window);
        Area destArea(325, 225, 150, 150);
        image.render(destArea);
        window.render();
        usleep(3000000);

    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
