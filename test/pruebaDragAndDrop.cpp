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
#include <list>
#include <iostream>
#include <unistd.h>
#include "World.h"
#include "Player.h"
#include "MouseManager.h"

bool leftMouseButtonDown = false;

static bool handleEvents(Area &area, SDL_Point& mousePos, SDL_Point& clickOffset) {
    SDL_Event event;
    // Para el alumno: Buscar diferencia entre waitEvent y pollEvent
    while (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_KEYDOWN: {
                // ¿Qué pasa si mantengo presionada la tecla?    
                const Uint8 *state = SDL_GetKeyboardState(NULL);
                if (state[SDL_SCANCODE_LEFT]){
                    std::cout<<"Movi a la izquierda"<< std::endl;
                }
                if (state[SDL_SCANCODE_RIGHT]){
                    std::cout<<"Movi a la DERECHa"<< std::endl;
                }
                if (state[SDL_SCANCODE_DOWN]){
                    std::cout<<"Movi a abajo"<< std::endl;
                }
                if (state[SDL_SCANCODE_UP]){
                    std::cout<<"Movi a arriba"<< std::endl;
                }
            } // Fin KEY_DOWN
                break;
            case SDL_KEYUP: {
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_LEFT:
                        std::cout<<"Movi a solte la flecha izq"<< std::endl;
                        break;
                    case SDLK_RIGHT:
                        std::cout<<"Movi a solte la flecha der"<< std::endl;
                        break;
                    case SDLK_UP:
                        std::cout<<"Movi a solte la flecha up"<< std::endl;
                        break;
                    case SDLK_DOWN:
                        std::cout<<"Movi a solte la flecha down"<< std::endl;
                        break;
                    } 
                }
                break;

            case SDL_MOUSEMOTION:{
	            	mousePos = { event.motion.x, event.motion.y };
				    if (leftMouseButtonDown){
			            area.setX(mousePos.x - clickOffset.x);
			            area.setY(mousePos.y - clickOffset.y);
	        		}
			}
            break;

            case SDL_MOUSEBUTTONDOWN: {
            	if (!leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT){
			        leftMouseButtonDown = true;
			    }
			}
			break;

			case SDL_MOUSEBUTTONUP:{
			   leftMouseButtonDown = false;
			}
			break;

            case SDL_QUIT:
                std::cout << "Quit :(" << std::endl;
                return false;
        } // fin switch(event)
    } // fin while(SDL_PollEvents)
    return true;
}

int main(int argc, const char *argv[]){
	Window window("Counter Strike 2D", 800, 600, 
                      SDL_WINDOW_RESIZABLE, 
                      SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    Image de_dust("assets/gfx/tiles/default_dust.png", window);
    

    SDL_Point mousePos = {0, 0};
    SDL_Point clickOffset = {0, 0};
    Area area(0, 0, 50, 50);

    bool running = true;
    while (running) {
    	window.clear();
    	running = handleEvents(area, mousePos, clickOffset);
	    de_dust.render(area);
	    window.render();
	}
    

	return 0;
}
