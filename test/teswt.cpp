#include "Image.h"
#include "Window.h"
#include <utility>
#include <unistd.h>
#include <iostream>

int main(){

    Window window("Counter Strike 2D", 800, 600,SDL_WINDOW_RESIZABLE, 
                      SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    Image img1("assets/gfx/tiles/default_dust.png",window);
    Area area1(0,0,200,200);

    img1.render(area1);
    window.render();
    
    usleep(4000000);
    window.clear();

    Image img2("assets/gfx/tiles/default_inferno.png",window);
    Area area3(0,0,50,50);
    img1 = std::move(img2);

    img1.render(area3);
    window.render();

    usleep(4000000);   
    return 0;
}