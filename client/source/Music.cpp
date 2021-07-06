#include "Music.h"

Music::Music(const std::string &musicPath) 
	: sdlMusic(musicPath.c_str()) { }

Music::Music(Music &&other) : sdlMusic(std::move(other.sdlMusic)) { }

Music::~Music() { }

Music& Music::operator=(Music &&other) {
	if (this == &other) return *this;
	sdlMusic = std::move(other.sdlMusic);
	return *this;
}

void Music::playMusic(int loops) const {
	sdlMusic.mixPlayMusic(loops);
}
