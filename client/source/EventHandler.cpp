#include "EventHandler.h"


bool EventHandler::handleEvents(Soldier &soldier, Player &player, float angle){
    SDL_Event event;
    // Para el alumno: Buscar diferencia entre waitEvent y pollEvent
    while (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_KEYDOWN: {
                // ¿Qué pasa si mantengo presionada la tecla?    
                const Uint8 *state = SDL_GetKeyboardState(NULL);
                if (state[SDL_SCANCODE_LEFT]){
                    soldier.move();
                    player.moveLeft(); // 
                }
                if (state[SDL_SCANCODE_RIGHT]){
                    soldier.move();
                    player.moveRight();// aca es prot.moveRoght
                }
                if (state[SDL_SCANCODE_DOWN]){
                    soldier.move();
                    player.moveDown();
                }
                if (state[SDL_SCANCODE_UP]){
                    soldier.move();
                    player.moveUp();
                }
            } // Fin KEY_DOWN
                break;
            case SDL_KEYUP: {
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_LEFT:
                        soldier.stopMoving();
                        player.stopMoveLeft();
                        break;
                    case SDLK_RIGHT:
                        soldier.stopMoving();
                        player.stopMoveRight();
                        break;
                    case SDLK_UP:
                        soldier.stopMoving();
                        player.stopMoveUp();
                        break;
                    case SDLK_DOWN:
                        soldier.stopMoving();
                        player.stopMoveDown();
                        break;
                    } 
                }// Fin KEY_UP
                break;
            case SDL_QUIT:
                std::cout << "Quit :(" << std::endl;
                return false;
            case SDL_MOUSEBUTTONDOWN:
                player.attack(angle - 90);
        } // fin switch(event)
    } // fin while(SDL_PollEvents)
    return true;
}