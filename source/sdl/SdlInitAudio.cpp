#include "SdlInitAudio.h"
#include "SdlException.h"
#include <SDL2/SDL_mixer.h>

SdlInitAudio::SdlInitAudio(int frequency, uint16_t format, int channels, int chunksize) {
    createInit(frequency, format, channels, chunksize);
}

void SdlInitAudio::createInit(int frequency, uint16_t format, int channels, int chunksize) {
    int errCode = Mix_OpenAudio(frequency, format, channels, chunksize);
    if (errCode < 0) {
        throw SdlException("SdlInitAudio no pudo inicializar. SDL_Error:");
    }    
}

void SdlInitAudio::destroyInit() {
    Mix_Quit();
}

SdlInitAudio::SdlInitAudio(SdlInitAudio &&other) { 
    createInit(other.frequency, other.format, other.channels, other.chunksize);
    other.destroyInit();
}

SdlInitAudio::~SdlInitAudio() { 
    destroyInit();
}

SdlInitAudio& SdlInitAudio::operator=(SdlInitAudio &&other) {
    if (this == &other) return *this;
    destroyInit();
    createInit(other.frequency, other.format, other.channels, other.chunksize);
    other.destroyInit();
    return *this;
}
