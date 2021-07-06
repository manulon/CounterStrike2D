#ifndef _SDL_FONT_H_
#define _SDL_FONT_H_

#include "SdlInitFont.h"
#include <SDL2/SDL_ttf.h>

class SdlFont {
	private:
		SdlInitFont initFont;
		TTF_Font *font;

		SdlFont(const SdlFont &other) = delete;
		SdlFont& operator=(const SdlFont &other) = delete;
		void destroyFont();

	public:
		SdlFont(const char *file, int ptsize);
		SdlFont(SdlFont &&other);
		~SdlFont();
		SdlFont& operator=(SdlFont &&other);
		TTF_Font* getFont() const;
};

#endif // _SDL_FONT_H_
