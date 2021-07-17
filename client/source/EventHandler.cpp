#include "EventHandler.h"


bool EventHandler::handleEvents(/*Soldier &soldier, Player &player, float angle*/){
    SDL_Event event;
    bool keepRunning = true; 
    
    while (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_KEYDOWN: {// todas las llamadas al player son al protocol en realidad
                const Uint8 *state = SDL_GetKeyboardState(NULL);
                if (state[SDL_SCANCODE_LEFT]){
                    protocol.moveLeft();
                    //soldier.move();
                    //player.moveLeft();
                }
                if (state[SDL_SCANCODE_RIGHT]){
                    protocol.moveRight();
                    //soldier.move();
                    //player.moveRight();
                }
                if (state[SDL_SCANCODE_DOWN]){
                    std::cout << "Tecla abajo" << std::endl;
                    protocol.moveDown();
                    //soldier.move();
                    //player.moveDown();
                }
                if (state[SDL_SCANCODE_UP]){
                    protocol.moveUp();
                    //soldier.move();
                    //player.moveUp();
                }
                if (state[SDL_SCANCODE_Q]){
                    //player.pickUpWeapon();
                }
            }
                break;
            case SDL_KEYUP: {
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_LEFT:
                        protocol.stopMoveLeft();
                        //soldier.stopMoving();
                        //player.stopMoveLeft();
                        break;
                    case SDLK_RIGHT:
                        protocol.stopMoveRight();
                        //soldier.stopMoving();
                        //player.stopMoveRight();
                        break;
                    case SDLK_UP:
                        protocol.stopMoveUp();
                        //soldier.stopMoving();
                        //player.stopMoveUp();
                        break;
                    case SDLK_DOWN:
                        std::cout << "Tecla arriba" << std::endl;
                        //soldier.stopMoving();
                        protocol.stopMoveDown();
                        //player.stopMoveDown();
                        break;
                    case SDLK_q:
                        //player.stopPickingUpWeapon();
                        break;
                    } 
                }
                break;
            case SDL_QUIT:
                protocol.quit();
                std::cout << "Quit :(" << std::endl;
                keepRunning = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                std::cout << "ENtre a buton down" << std::endl;
                protocol.attack();
                //player.attack(angle - 90);
                //keepRunning = false;
                break;
        }
    }
    return keepRunning;
}