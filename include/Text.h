#ifndef _TEXT_H_
#define _TEXT_H_

#include "SdlFont.h"
#include "SdlTexture.h"
class SdlRenderer;
class Window;
class Area;

class Text {
	private:
		SdlFont sdlFont;
		SdlTexture sdlTexture;
		SdlRenderer &sdlRenderer;

	public:
		Text(const char *fontPath, int ptsize,
		     const char *textToRender, 
		     SDL_Color color, 
		     Window &window);
		~Text();
		void render(const Area &dest) const;
        //void render(const Area &src, const Area &dest) const;
        //void render(const Area &src, const Area &dest, float angle, const SDL_RendererFlip &flipType) const;
};

#endif // _TEXT_H_