#ifndef _SDL_SOUND_EFFECT_H_
#define _SDL_SOUND_EFFECT_H_

#include "SdlInitAudio.h"
class Mix_Chunk;

class SdlSoundEffect {
	private:
		SdlInitAudio sdlInitAudio;
		Mix_Chunk *soundEffect;
		SdlSoundEffect(const SdlSoundEffect &other) = delete;
		SdlSoundEffect& operator=(const SdlSoundEffect &other) = delete;
		void destroySoundEffect();

	public:
		SdlSoundEffect(const char *path);
		SdlSoundEffect(SdlSoundEffect &&other);
		~SdlSoundEffect();
		SdlSoundEffect& operator=(SdlSoundEffect &&other);
		void mixPlayChannel(int channel, int loops) const;
};

#endif // _SDL_SOUND_EFFECT_H_
