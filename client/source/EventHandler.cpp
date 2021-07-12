#include "EventHandler.h"


bool EventHandler::handleEvents(/*Soldier &soldier, Player &player, float angle*/){
    /*SDL_Event event;
    
    while (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_KEYDOWN: {// todas las llamadas al player son al protocol en realidad
                const Uint8 *state = SDL_GetKeyboardState(NULL);
                if (state[SDL_SCANCODE_LEFT]){
                    //soldier.move();
                    //player.moveLeft();
                }
                if (state[SDL_SCANCODE_RIGHT]){
                    //soldier.move();
                    //player.moveRight();
                }
                if (state[SDL_SCANCODE_DOWN]){
                    //soldier.move();
                    //player.moveDown();
                }
                if (state[SDL_SCANCODE_UP]){
                    //soldier.move();
                    //player.moveUp();
                }
            }
                break;
            case SDL_KEYUP: {
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_LEFT:
                        //soldier.stopMoving();
                        //player.stopMoveLeft();
                        break;
                    case SDLK_RIGHT:
                        //soldier.stopMoving();
                        //player.stopMoveRight();
                        break;
                    case SDLK_UP:
                        //soldier.stopMoving();
                        //player.stopMoveUp();
                        break;
                    case SDLK_DOWN:
                        //soldier.stopMoving();
                        //player.stopMoveDown();
                        break;
                    } 
                }
                break;
            case SDL_QUIT:
                //protocol.quit();
                std::cout << "Quit :(" << std::endl;
                return false;
            case SDL_MOUSEBUTTONDOWN:
                std::cout << "ELIMINAR ESTE COUT\n";
                protocol.attack();
                return false;
                //player.attack(angle - 90);
        }
    }*/
    
    protocol.moveLeft();
    protocol.moveRight();
    protocol.moveUp();
    protocol.moveDown();
    protocol.stopMoveRight();
    protocol.stopMoveLeft();
    protocol.stopMoveUp();
    protocol.stopMoveDown();
    protocol.attack();
    protocol.quit();
    return false;
}