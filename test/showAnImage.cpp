#include "Window.h"
#include "SdlInit.h"
//#include "SdlWindow.h"
#include "SdlRenderer.h"
#include "SdlTexture.h"
#include "Area.h"
#include "Image.h"
#include <SDL2/SDL.h>
#include <exception>
#include <iostream>
#include <unistd.h>

int main(int argc, const char *argv[]){
    try {
        Window window("Ventana de prueba", 800, 600, 0);
        window.fill();
        Image image("assets/gfx/backgrounds/toxic.jpg", window);
        Area srcArea(0, 0, 300, 300);
        Area destArea(100, 100, 300, 300);
        image.render(srcArea, destArea, SDL_FLIP_NONE);
        window.render();
        usleep(3000000);
        
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
