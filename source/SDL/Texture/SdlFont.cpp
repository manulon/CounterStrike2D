#include "SdlFont.h"
#include "SdlFontException.h"

SdlFont::SdlFont(const char *file, int ptsize) : initFont() {
	font = TTF_OpenFont(file, ptsize);
	if (font == nullptr) {
		throw SdlFontException("No pudo crear la fuente de texto. SDL_Error:");
	}
}

SdlFont::SdlFont(SdlFont &&other) 
	: initFont(std::move(other.initFont)), 
	  font(other.font) {
	other.font = nullptr;
}

void SdlFont::destroyFont() {
	if (font != nullptr) {
		TTF_CloseFont(font);
	}
}

SdlFont::~SdlFont() {
	destroyFont();
}

SdlFont& SdlFont::operator=(SdlFont &&other) {
	if (this == &other) return *this;
	destroyFont();
	initFont = std::move(other.initFont);
	font = other.font;
	other.font = nullptr;
	return *this;
}

TTF_Font* SdlFont::getFont() const {
	return font;
}
