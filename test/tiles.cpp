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

int main(int argc, const char *argv[]){
    Window window("Prueba para tiles", 800, 800, 
                      SDL_WINDOW_RESIZABLE, 
                      SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    Image de_dust("assets/gfx/tiles/default_dust.png", window);
    Image obsImg("assets/gfx/tiles/dust.bmp", window);
    Area windowArea(0, 0, 800, 800);



    TileMap mapTest("assets/maps/testMap.txt", de_dust, obsImg);
        
    //mapTest.render(windowArea);

    window.render();
            
    usleep(50000000);    
        
    return 0;
}
