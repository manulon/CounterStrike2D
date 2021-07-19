#include "PlayerMovementEvent.h"

PlayerMovementEvent::PlayerMovementEvent(short id, char opcode) : ServerEvent(id), opcode(opcode){}

void PlayerMovementEvent::handle(Game &game){
    game.playerMovement(id, opcode);
}