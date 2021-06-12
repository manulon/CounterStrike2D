#include "SdlInit.h"
#include "SdlException.h"
#include <SDL2/SDL.h>

SdlInit::SdlInit(uint32_t flags) : flags(flags) {
    createInit(flags);
}

void SdlInit::createInit(uint32_t flags) {
    int errCode = SDL_Init(flags);
    if (errCode < 0) {
        throw SdlException("SdlInit no pudo inicializar. SDL_Error:");
    }
}

SdlInit::SdlInit(SdlInit &&other) {
    createInit(other.flags);
    other.destroyInit();
}

void SdlInit::destroyInit() {
    SDL_Quit();
}

SdlInit::~SdlInit() { 
    destroyInit();
}

SdlInit& SdlInit::operator=(SdlInit &&other) {
    if (this == &other) return *this;
    destroyInit();
    createInit(other.flags);
    other.destroyInit();
    return *this;
}
