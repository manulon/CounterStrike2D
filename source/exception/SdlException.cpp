#include "SdlException.h"
#include <SDL2/SDL.h>

SdlException::SdlException(const char *description) noexcept
    : Exception("%s [%s]", description, SDL_GetError()) { }

SdlException::~SdlException() noexcept { }
