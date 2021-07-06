#include "SdlSoundEffect.h"
#include "SdlMixException.h"
#include <SDL2/SDL_mixer.h>

#define FREQUENCY 44100
#define CHANNELS 2
#define CHUNK_SIZE 2048

SdlSoundEffect::SdlSoundEffect(const char *path) 
	: sdlInitAudio(FREQUENCY, MIX_DEFAULT_FORMAT, CHANNELS, CHUNK_SIZE) {
	soundEffect = Mix_LoadWAV(path);
	if (soundEffect == nullptr) {
		throw SdlMixException("No se pudo crear en efecto de sonido. SDL_Error:");
	}
}

SdlSoundEffect::SdlSoundEffect(SdlSoundEffect &&other) 
    : sdlInitAudio(std::move(other.sdlInitAudio)), 
      soundEffect(other.soundEffect) {
    other.soundEffect = nullptr;
}

void SdlSoundEffect::destroySoundEffect() {
    if (soundEffect != nullptr) {
        Mix_FreeChunk(soundEffect);
    }
}

SdlSoundEffect::~SdlSoundEffect() {
    destroySoundEffect();
}

SdlSoundEffect& SdlSoundEffect::operator=(SdlSoundEffect &&other) {
    if (this == &other) return *this;
    destroySoundEffect();
    sdlInitAudio = std::move(other.sdlInitAudio);
    soundEffect = other.soundEffect;
    other.soundEffect = nullptr;
    return *this;
}

void SdlSoundEffect::mixPlayChannel(int channel, int loops) const {
    int errCode = Mix_PlayChannel(channel, soundEffect, loops);
    if (errCode == -1) {
        throw SdlMixException("No se pudo reproducir en efecto de sonido. SDL_Error:");
    }
}
