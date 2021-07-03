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
#include "Obstacle.h"
#include "MouseManager.h"
#include "PhysicalMapFactory.h"
#include "FireArm.h"
#include "Pointer.h"
#include "Weapon.h"
#define PPM 32

static bool handleEvents(Soldier &soldier,Camera& camera, Player &player, float angle) {
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
            case SDL_MOUSEBUTTONDOWN:
                player.shoot(angle - 90);
        } // fin switch(event)
    } // fin while(SDL_PollEvents)
    return true;
}

static void update(Soldier &soldier,Player &player, float dt, MouseManager &mm) {
    soldier.update(dt);
    mm.update();
    soldier.setAngle(mm.getAngle());
    player.update();
}

int main(int argc, const char *argv[]){
    try {
        World world;
        Player player(world, 
    				  0.0f, 0.0f, 
    				  0.45f, 0.45f,0);
        Player player2(world, 
    				  1.0f, 0.0f, 
    				  0.45f, 0.45f,1);
        Window window("Counter Strike 2D", 800, 600, 
                      SDL_WINDOW_RESIZABLE, 
                      SDL_INIT_VIDEO | SDL_INIT_AUDIO);

        Image de_dust("assets/gfx/tiles/default_dust.png", window);
        Image obsimg("assets/gfx/tiles/dust.bmp", window);
        TileMap mapTest("assets/maps/mapTest.yaml", de_dust, obsimg);
        // TileMap mapTest("pepe.yaml", de_dust, obsimg);
        PhysicalMapFactory g(world,"assets/maps/mapTest.yaml");
        // PhysicalMapFactory g(world,"pepe.yaml");
        Image pointImg("assets/gfx/pointer.bmp",window);
        Pointer pointer(pointImg);
        Camera camera(mapTest);
        // Obstacle obs(world,1,1,0.5f,0.5f);
        Image soldier_img1("assets/gfx/player/t1.bmp", window);
        Image soldier_img2("assets/gfx/player/t4.bmp", window);
        Soldier soldier_renderer(soldier_img2);
        Soldier soldier_renderer2(soldier_img1);
        Music music("assets/sfx/menu.wav");
        FireArm fa(world, 0.3f,0.3f,10,2);
        fa.earlyAttachToWorld(2,3);
        Image weaponImg("assets/gfx/weapons/ak47_d.bmp",window);
        Weapon weapon(weaponImg,16,32);
        SoundEffect soundEffect("assets/sfx/weapons/ak47.wav");
        Stencil stencil(1000, 1000, 25, 90, 150, window);
        SDL_Color textColor {0,0,0};
        Text text("assets/gfx/fonts/liberationsans.ttf", 200,
                  "Hola Mundo !", textColor, window);

        std::list<Entity*> serverObjects;
        // serverObjects.push_back(&player);
        serverObjects.push_back(&player2);
        serverObjects.push_back(&fa);

        Area stencilArea((800/2)-(1000/2), (600/2)-(1000/2), 1000, 1000);
        Area textArea((800/2)-(200/2), (600/2)-(100/2), 200, 100);       
        Area cameraArea(0, 0, 800, 600);
        MouseManager mm(800,600);
        bool running = true;
        int i = 0;
        mapTest.addDynamicObject(player2.getId(), &soldier_renderer2);
        mapTest.addDynamicObject(fa.getId(),&weapon);
        // int offsetY = g.getHeight()/2 - window.getHeight()/32/2 - 1  ;
        // int offsetX = g.getWidth()/2 - window.getWidth()/32/2 - 1  ;
        // std::cout <<offsetY <<std::endl;
        while (running) {
            
            running = handleEvents(soldier_renderer,camera, player, mm.getAngle());
            update(soldier_renderer,player, FRAME_RATE,mm);
            mapTest.update(serverObjects);
            window.clear();
            world.step();
            camera.render(player.getPositionX()*32,(player.getPositionY()+3)*32, cameraArea);
            stencil.render(stencilArea, mm.getAngle());
            // text.render(textArea);
            soldier_renderer.render();
            pointer.render(mm.getPositionX(),mm.getPositionY());
            window.render();
            usleep(FRAME_RATE);  
            if (i%15 == 0){
                // std::cout<<"player x: "<<player.getPositionX()<<" y: "<<player.getPositionY()<<std::endl;
                // std::cout <<"angle: "<<mm.getAngle()<<std::endl;
                // std::cout <<"firearm: "<<fa.getPositionX()<<" y: "<<fa.getPositionY()<<std::endl;
                // std::cout<<"mouse x: "<<mm.getPositionX()<<" y: "<<mm.getPositionY()<<std::endl;
                // std::cout <<"x: "<< soldier_renderer2.getX()<<" y: "<<soldier_renderer2.getY()<<std::endl;
            }
            i++;  
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
