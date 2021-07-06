#include "SdlFontException.h"
#include <SDL2/SDL_ttf.h>

SdlFontException::SdlFontException(const char *description) noexcept
    : Exception("%s [%s]", description, TTF_GetError()) { }

SdlFontException::~SdlFontException() noexcept { }
