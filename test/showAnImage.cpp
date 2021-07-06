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
#include "SWeapon.h"
#include "Pointer.h"
#include "Weapon.h"
#include "Ak47.h"
#include "EventHandler.h"
#define PPM 32


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
    				  3.0f, 0.0f, 
    				  0.45f, 0.45f,100);
        Player player2(world, 
    				  1.0f, 0.0f, 
    				  0.45f, 0.45f,0);

        // CREACION ARMA Y SETEO A PLAYER
        std::unique_ptr<Ak47> ak47(new Ak47(world, 0.2f, 0.2f));
        std::unique_ptr<SWeapon> weapon(new SWeapon(world, std::move(ak47)));
        player.setWeapon(std::move(weapon));

        std::unique_ptr<Ak47> a(new Ak47(world, 0.2f, 0.2f));
        std::unique_ptr<SWeapon> weap(new SWeapon(world, std::move(a)));
        player2.setWeapon(std::move(weap));

        Window window("Counter Strike 2D", 800, 600, 
                      SDL_WINDOW_RESIZABLE, 
                      SDL_INIT_VIDEO | SDL_INIT_AUDIO);

        //Image de_dust("assets/gfx/tiles/default_dust.png", window);
        //Image obsimg("assets/gfx/tiles/obstacles.png", window);
        // TileMap mapTest(window,"assets/maps/SmallDust.yaml", de_dust, obsimg);
        TileMap mapTest(window, "mapaGiganteDust.yaml", "assets/gfx/tiles/default_dust.png", "assets/gfx/tiles/obstacles.png");
        // PhysicalMapFactory g(world,"assets/maps/SmallDust.yaml");
        PhysicalMapFactory g(world,"mapaGiganteDust.yaml");
        Image pointImg("assets/gfx/pointer.bmp",window);
        Pointer pointer(pointImg);
        Camera camera(mapTest);
        Soldier soldier_renderer("assets/gfx/player/t4.bmp", window);
        Music music("assets/sfx/menu.wav");

        /*std::unique_ptr<FireArm> fa(new FireArm(world, 0.3f, 0.3f, 1, 11));
        fa->earlyAttachToWorld(2.0f, 3.0f);
        world.spawnFireArm(std::move(fa));*/

        std::unique_ptr<Ak47> ak(new Ak47(world, 0.2f, 0.2f));
        std::unique_ptr<SWeapon> w(new SWeapon(world, std::move(ak)));
        w->earlyAttachToWorld(4.3f, 8.0f);
        world.spawnWeapon(std::move(w));


        SoundEffect soundEffect("assets/sfx/weapons/ak47.wav");
        Stencil stencil(1000, 1000, 25, 90, 150, window);
        SDL_Color textColor {0,0,0};
        Text text("assets/gfx/fonts/liberationsans.ttf", 200,
                  "Hola Mundo !", textColor, window);

        std::list<Entity*> serverObjects;
        // serverObjects.push_back(&player);
        // serverObjects.push_back(&player2);
        // serverObjects.push_back(&fa);

        Area stencilArea((800/2)-(1000/2), (600/2)-(1000/2), 1000, 1000);
        Area textArea((800/2)-(200/2), (600/2)-(100/2), 200, 100);       
        Area cameraArea(0, 0, 800, 600);
        MouseManager mm(800,600);
        bool running = true;
        int i = 0;
        EventHandler eh;
        while (running) {
            
            running = eh.handleEvents(soldier_renderer, player, mm.getAngle());
            update(soldier_renderer,player, FRAME_RATE,mm);
            window.clear();
            world.step();
            world.getServerObjects(serverObjects);
            camera.render((player.getPositionX()+8)*32,(player.getPositionY()-2)*32, cameraArea, serverObjects);
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
                // std::cout<<world<<std::endl;
            i++;  
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
