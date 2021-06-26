#include "Window.h"
#include "Image.h"
#include "Area.h"
#include "Stencil.h"
#include "Music.h"
#include "SoundEffect.h"
#include "Text.h"
#include "Camera.h"
#include "Soldier.h"
#include "Animation.h"
#include "TileMap.h"
#include <SDL2/SDL.h>
#include <exception>
#include <iostream>
#include <unistd.h>
#include "World.h"
#include "Player.h"
#include "MouseManager.h"

static bool handleEvents(Soldier &soldier,Camera& camera, Player &player) {
    SDL_Event event;
    // Para el alumno: Buscar diferencia entre waitEvent y pollEvent

    while (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_KEYDOWN: {
                // ¿Qué pasa si mantengo presionada la tecla?    
                const Uint8 *state = SDL_GetKeyboardState(NULL);
                if (state[SDL_SCANCODE_LEFT]){
                    soldier.move(LEFT);
                    player.moveLeft();
                }
                if (state[SDL_SCANCODE_RIGHT]){
                    soldier.move(RIGHT);
                    player.moveRight();
                }
                if (state[SDL_SCANCODE_DOWN]){
                    soldier.move(DOWN);
                    player.moveDown();
                }
                if (state[SDL_SCANCODE_UP]){
                    soldier.move(UP);
                    player.moveUp();
                }
            } // Fin KEY_DOWN
                break;
            case SDL_KEYUP: {
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_LEFT:
                        soldier.stopLeft();
                        player.stopMoveLeft();
                        break;
                    case SDLK_RIGHT:
                        soldier.stopRight();
                        player.stopMoveRight();
                        break;
                    case SDLK_UP:
                        soldier.stopUp();
                        player.stopMoveUp();
                        break;
                    case SDLK_DOWN:
                        soldier.stopDown();
                        player.stopMoveDown();
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

static void update(Soldier &soldier,Player &player, float dt, MouseManager &mm) {
    soldier.update(dt);
    soldier.setAngle(mm.getAngle());
    player.update();
}

int main(int argc, const char *argv[]){
    try {
        World world;
        Player player(world, 
    				  0.0f, 4.0f, 
    				  1.0f, 1.0f);
        Window window("Counter Strike 2D", 800, 600, 
                      SDL_WINDOW_RESIZABLE, 
                      SDL_INIT_VIDEO | SDL_INIT_AUDIO);

        Image de_dust("assets/gfx/tiles/default_dust.png", window);
        TileMap mapTest("assets/maps/testMap.txt", de_dust);

        Camera camera(mapTest);
        
        Image soldier_img1("assets/gfx/player/t4.bmp", window);
        Image soldier_img2("assets/gfx/player/t4.bmp", window);
        Soldier soldier_renderer(soldier_img2);

        Music music("assets/sfx/menu.wav");
        SoundEffect soundEffect("assets/sfx/weapons/ak47.wav");
        Stencil stencil(1000, 1000, 25, 90, 150, window);
        SDL_Color textColor {0,0,0};
        Text text("assets/gfx/fonts/liberationsans.ttf", 200,
                  "Hola Mundo !", textColor, window);

        Area stencilArea((800/2)-(1000/2), (600/2)-(1000/2), 1000, 1000);
        Area textArea((800/2)-(200/2), (600/2)-(100/2), 200, 100);       
        Area cameraArea(0, 0, 800, 800);
        MouseManager mm;
        bool running = true;
        while (running) {
            running = handleEvents(soldier_renderer,camera, player);
            update(soldier_renderer,player, FRAME_RATE,mm);
            window.clear();
            world.step();
            camera.render(player.getPositionX()*75,player.getPositionY()*75, cameraArea);
            stencil.render(stencilArea, mm.getAngle());
            text.render(textArea);
            soldier_renderer.render();
            window.render();
            usleep(FRAME_RATE);    
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
