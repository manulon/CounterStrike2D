#include "EventHandler.h"
#include "MouseManager.h"

bool EventHandler::handleEvents(){
    SDL_Event event;
    bool keepRunning = true; 
    MouseManager mm(800,600);
    short angle(mm.getAngle());
    map.setSoldierDirection(angle);
    protocol.sendAngle(angle);
    map.setPointerPosition(mm.getPositionX(),mm.getPositionY());
    while (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_KEYDOWN: {
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
                    protocol.pickUpWeapon();
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
                        //soldier.stopMoving();
                        protocol.stopMoveDown();
                        //player.stopMoveDown();
                        break;
                    case SDLK_q:
                        protocol.stopPickingUpWeapon();
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
                protocol.attack(mm.getAngle());
                std::cout<<"angulo del mouseMAnager"<<mm.getAngle()-90<<std::endl;
                //player.attack(angle - 90);
                break;
        }
    }
    return keepRunning;
}