#include "SdlInit.h"
#include "SdlException.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

SdlInit::SdlInit(std::uint32_t flags) {
	int errCode = SDL_Init(flags);
    if (errCode < 0) {
        throw SdlException("SdlInit no pudo inicializar. SDL_Error:");
    }
}

void SdlInit::destroyInit() {
    SDL_Quit();
}

SdlInit::SdlInit(SdlInit &&other) { 
    other.destroyInit();
}

SdlInit::~SdlInit() { 
    //SDL_Quit();
    destroyInit();
}

SdlInit& SdlInit::operator=(SdlInit &&other) {
    if (this == &other) return *this;
    other.destroyInit();
    return *this;
}
