#include "EventHandler.h"


bool EventHandler::handleEvents(Soldier &soldier, Player &player, float angle){
    SDL_Event event;
    // Para el alumno: Buscar diferencia entre waitEvent y pollEvent
    while (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_KEYDOWN: {
                // ¿Qué pasa si mantengo presionada la tecla?    
                const Uint8 *state = SDL_GetKeyboardState(NULL);
                if (state[SDL_SCANCODE_A]){
                    soldier.move();
                    player.moveLeft(); // 
                }
                if (state[SDL_SCANCODE_D]){
                    soldier.move();
                    player.moveRight();// aca es prot.moveRoght
                }
                if (state[SDL_SCANCODE_S]){
                    soldier.move();
                    player.moveDown();
                }
                if (state[SDL_SCANCODE_W]){
                    soldier.move();
                    player.moveUp();
                }
            } // Fin KEY_DOWN
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