#include "SoundEffect.h"

SoundEffect::SoundEffect(const std::string &soundEffectPath) 
	: sdlSoundEffect(soundEffectPath.c_str()) { }

SoundEffect::SoundEffect(SoundEffect &&other) : sdlSoundEffect(std::move(other.sdlSoundEffect)) { }

SoundEffect::~SoundEffect() { }

SoundEffect& SoundEffect::operator=(SoundEffect &&other) {
	if (this == &other) return *this;
	sdlSoundEffect = std::move(other.sdlSoundEffect);
	return *this;
}

void SoundEffect::playEffect(int channel, int loops) const {
	sdlSoundEffect.mixPlayChannel(channel, loops);
}
