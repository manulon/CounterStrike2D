#include "SdlMixException.h"
#include <SDL2/SDL_mixer.h>

SdlMixException::SdlMixException(const char *description) noexcept
    : Exception("%s [%s]", description, Mix_GetError()) { }

SdlMixException::~SdlMixException() noexcept { }