#include "Window.h"
#include "Image.h"
#include "Area.h"
#include "Stencil.h"
#include "Music.h"
#include "SoundEffect.h"
#include <SDL2/SDL.h>
#include <exception>
#include <iostream>
#include <unistd.h>

int main(int argc, const char *argv[]){
    try {
        // SE MEZCLAN LOS FUNCIONAMIENTOS DE RENDERIZADO Y SONIDO
        // YA FUNCIONA CARGAR SONIDOS.

        Window window("Counter Strike 2D", 800, 600, 
                      SDL_WINDOW_RESIZABLE, 
                      SDL_INIT_VIDEO | SDL_INIT_AUDIO);
        Image image("assets/gfx/backgrounds/toxic.jpg", window);
        Music music("assets/sfx/menu.wav");
        SoundEffect soundEffect("assets/sfx/weapons/ak47.wav");
        Stencil stencil(1000, 1000, 25, 90, 150, window); 
        Area imageArea(0, 0, 800, 600);
        Area stencilArea((800/2)-(1000/2), (600/2)-(1000/2), 1000, 1000);
        image.render(imageArea);
        stencil.render(stencilArea, 0);
        window.render();
        music.playMusic(-1);
        soundEffect.playEffect(-1, 4);
        usleep(3000000);

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
