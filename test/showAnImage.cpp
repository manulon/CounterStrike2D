#include "Window.h"
#include "Image.h"
#include "Area.h"
#include "Stencil.h"
#include "Music.h"
#include "SoundEffect.h"
#include "Text.h"
#include "Soldier.h"
#include "Animation.h"
#include <SDL2/SDL.h>
#include <exception>
#include <iostream>
#include <unistd.h>

static bool handleEvents(Soldier &soldier) {
    SDL_Event event;
    // Para el alumno: Buscar diferencia entre waitEvent y pollEvent
    while(SDL_PollEvent(&event)){
        switch(event.type) {
            case SDL_KEYDOWN: {
                // ¿Qué pasa si mantengo presionada la tecla?    
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_LEFT:
                        soldier.moveLeft();
                        break;
                    case SDLK_RIGHT:
                        soldier.moveRigth();
                        break;
                    case SDLK_UP:
                        soldier.moveUp();
                        break;
                    case SDLK_DOWN:
                        soldier.moveDown();
                        break;
                    }
                } // Fin KEY_DOWN
                break;
            case SDL_KEYUP: {
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_LEFT:
                        soldier.stopMoving();
                        break;
                    case SDLK_RIGHT:
                        soldier.stopMoving();
                        break;
                    case SDLK_UP:
                        soldier.stopMoving();
                        break;
                    case SDLK_DOWN:
                        soldier.stopMoving();
                        break;
                    } 
                }// Fin KEY_UP
                break;
            case SDL_MOUSEMOTION:
                break;
            case SDL_QUIT:
                std::cout << "Quit :(" << std::endl;
                return false;
        } // fin switch(event)
    } // fin while(SDL_PollEvents)
    return true;
}

static void update(Soldier &soldier, float dt) {
    soldier.update(dt);
}


int main(int argc, const char *argv[]){
    try {

        Window window("Counter Strike 2D", 800, 600, 
                      SDL_WINDOW_RESIZABLE, 
                      SDL_INIT_VIDEO | SDL_INIT_AUDIO);
        Image image("assets/gfx/backgrounds/toxic.jpg", window);

        Image soldier_img1("assets/gfx/player/t4.bmp", window);
        Image soldier_img2("assets/gfx/player/t4.bmp", window);
        Soldier soldier(soldier_img2);

        Music music("assets/sfx/menu.wav");
        SoundEffect soundEffect("assets/sfx/weapons/ak47.wav");
        Stencil stencil(1000, 1000, 25, 90, 150, window);
        SDL_Color textColor {0,0,0};
        Text text("assets/gfx/fonts/liberationsans.ttf", 200,
                  "Hola Mundo !", textColor, window);

        Area imageArea(0, 0, 800, 600);       
        Area stencilArea((800/2)-(1000/2), (600/2)-(1000/2), 1000, 1000);
        Area textArea((800/2)-(200/2), (600/2)-(100/2), 200, 100);       

        bool running = true;
        while (running) {
            image.render(imageArea);
            stencil.render(stencilArea, 225);
            text.render(textArea);

            running = handleEvents(soldier);
            
            update(soldier, FRAME_RATE);
            soldier.render();
            window.render();
            
            
            usleep(FRAME_RATE);
            
            window.clear();
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}

