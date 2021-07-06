#ifndef _SDL_MUSIC_H_
#define _SDL_MUSIC_H_

#include "SdlInitAudio.h"
#include <SDL2/SDL_mixer.h>

class SdlMusic {
	private:
		SdlInitAudio sdlInitAudio;
		Mix_Music *music;
		SdlMusic(const SdlMusic &other) = delete;
		SdlMusic& operator=(const SdlMusic &other) = delete;
		void destroyMusic();

	public:
		SdlMusic(const char *path);
		SdlMusic(SdlMusic &&other);
		~SdlMusic();
		SdlMusic& operator=(SdlMusic &&other);
		void mixPlayMusic(int loops) const;
		bool mixPlayingMusic() const;
		bool mixPausedMusic() const;
		void mixResumeMusic() const;
		void mixPauseMusic() const;
		void mixHaltMusic() const;
};

#endif // _SDL_MUSIC_H_
