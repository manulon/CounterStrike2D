#include "EventHandler.h"


bool EventHandler::handleEvents(Soldier &soldier, Player &player, float angle){
    SDL_Event event;
    
    while (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_KEYDOWN: {// todas las llamadas al player son al protocol en realidad
                const Uint8 *state = SDL_GetKeyboardState(NULL);
                if (state[SDL_SCANCODE_A]){
                    soldier.move();
                    player.moveLeft();
                }
                if (state[SDL_SCANCODE_D]){
                    soldier.move();
                    player.moveRight();
                }
                if (state[SDL_SCANCODE_S]){
                    soldier.move();
                    player.moveDown();
                }
                if (state[SDL_SCANCODE_W]){
                    soldier.move();
                    player.moveUp();
                }
            }
                break;
            case SDL_KEYUP: {
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_a:
                        soldier.stopMoving();
                        player.stopMoveLeft();
                        break;
                    case SDLK_d:
                        soldier.stopMoving();
                        player.stopMoveRight();
                        break;
                    case SDLK_w:
                        soldier.stopMoving();
                        player.stopMoveUp();
                        break;
                    case SDLK_s:
                        soldier.stopMoving();
                        player.stopMoveDown();
                        break;
                    } 
                }
                break;
            case SDL_QUIT:
                //protocol.quit();
                std::cout << "Quit :(" << std::endl;
                return false;
            case SDL_MOUSEBUTTONDOWN:
                //protocol.mouseDown()
                player.attack(angle - 90);
        }
    }
    return true;
}