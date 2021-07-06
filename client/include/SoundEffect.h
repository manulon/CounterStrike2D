#ifndef _SOUND_EFFECT_H_
#define _SOUND_EFFECT_H_

#include "SdlSoundEffect.h"
#include <string>

class SoundEffect {
    private:
        SdlSoundEffect sdlSoundEffect;

        SoundEffect(const SoundEffect &other) = delete;
        SoundEffect& operator=(const SoundEffect &other) = delete;
    
    public:
        SoundEffect(const std::string &soundEffectPath);
        SoundEffect(SoundEffect &&other);
        ~SoundEffect();
        SoundEffect& operator=(SoundEffect &&other);
        void playEffect(int channel, int loops) const;
};

#endif // _SOUND_EFFECT_H_
