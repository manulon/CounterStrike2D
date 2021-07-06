#include "SdlMusic.h"
#include "SdlMixException.h"

#define FREQUENCY 44100
#define CHANNELS 2
#define CHUNK_SIZE 2048

SdlMusic::SdlMusic(const char *path) 
    : sdlInitAudio(FREQUENCY, MIX_DEFAULT_FORMAT, CHANNELS, CHUNK_SIZE), 
      music(nullptr) {
    music = Mix_LoadMUS(path);
    if (music == nullptr) {
        throw SdlMixException("No se pudo crear la musica. SDL_Error:");
    }
}

SdlMusic::SdlMusic(SdlMusic &&other) 
    : sdlInitAudio(std::move(other.sdlInitAudio)), 
      music(other.music) {
    other.music = nullptr;

}

void SdlMusic::destroyMusic() {
    if (music != nullptr) {
        Mix_FreeMusic(music);
    }
}

SdlMusic::~SdlMusic() {
    destroyMusic();
}

SdlMusic& SdlMusic::operator=(SdlMusic &&other) {
    if (this == &other) return *this;
    destroyMusic();
    sdlInitAudio = std::move(other.sdlInitAudio);
    music = other.music;
    other.music = nullptr;
    return *this;
}

void SdlMusic::mixPlayMusic(int loops) const {
    int errCode = Mix_PlayMusic(music, loops);
    if (errCode == -1) {
        throw SdlMixException("No se pudo reproducir la musica. SDL_Error:");
    }
}

bool SdlMusic::mixPlayingMusic() const {
    return Mix_PlayingMusic(); // 1 if it is playing, 0 otherwise
}

bool SdlMusic::mixPausedMusic() const {
    return Mix_PausedMusic(); // 1 if it is paused, 0 otherwise
}

void SdlMusic::mixResumeMusic() const {
    Mix_ResumeMusic();
}

void SdlMusic::mixPauseMusic() const {
    Mix_PauseMusic();
}

void SdlMusic::mixHaltMusic() const {
    Mix_HaltMusic();
}
