#include "SdlInit.h"
#include "SdlException.h"
#include <SDL2/SDL.h>

SdlInit::SdlInit(std::uint32_t flags) {
	int errCode = SDL_Init(flags);
    if (errCode < 0) {
        throw SdlException("SdlInit no pudo inicializar. SDL_Error:");
    }
}

SdlInit::~SdlInit() { 
    SDL_Quit();
}
