#include "SdlImageException.h"
#include <SDL2/SDL_image.h>

SdlImageException::SdlImageException(const char *description) noexcept
    : Exception("%s [%s]", description, IMG_GetError()) { }

SdlImageException::~SdlImageException() noexcept { }