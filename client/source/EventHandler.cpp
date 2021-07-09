#include "EventHandler.h"


bool EventHandler::handleEvents(Soldier &soldier, Player &player, float angle){
    SDL_Event event;
    
    while (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_KEYDOWN: {
                const Uint8 *state = SDL_GetKeyboardState(NULL);
                if (state[SDL_SCANCODE_LEFT]){
                    //protocol.moveLeft();
                    soldier.move();
                    player.moveLeft();
                }
                if (state[SDL_SCANCODE_RIGHT]){
                    //protocol.moveRight();
                    soldier.move();
                    player.moveRight();
                }
                if (state[SDL_SCANCODE_DOWN]){
                    //protocol.moveDown();
                    soldier.move();
                    player.moveDown();
                }
                if (state[SDL_SCANCODE_UP]){
                    //protocol.moveUp();
                    soldier.move();
                    player.moveUp();
                }
            }
                break;
            case SDL_KEYUP: {
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_LEFT:
                        //protocol.stopMoveLeft();
                        soldier.stopMoving();
                        player.stopMoveLeft();
                        break;
                    case SDLK_RIGHT:
                        //protocol.stopMoveRight();
                        soldier.stopMoving();
                        player.stopMoveRight();
                        break;
                    case SDLK_UP:
                        //protocol.stopMoveUp();
                        soldier.stopMoving();
                        player.stopMoveUp();
                        break;
                    case SDLK_DOWN:
                        //protocol.stopMoveDown();
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