#include "GameEndedException.h"

GameEndedException::GameEndedException() noexcept
    : Exception("You Died") { }

GameEndedException::~GameEndedException() noexcept { }
