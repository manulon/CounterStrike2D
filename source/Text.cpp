#include "Text.h"
#include "SdlRenderer.h"
#include "Window.h"
#include "Area.h"

#define DEFAULT_ANGLE 0

Text::Text(const char *fontPath, int ptsize,
		   const char *textToRender, 
		   SDL_Color color, 
		   Window &window) 
	: sdlFont(fontPath, ptsize),
	  sdlTexture(textToRender, color, window.getRenderer(), sdlFont),
	  sdlRenderer(window.getRenderer()) { }

Text::~Text() { }

void Text::render(const Area &dest) const {
	SDL_Rect destrect = {dest.getX(), dest.getY(), 
                         dest.getWidth(), dest.getHeight()};
	sdlRenderer.renderCopy(sdlTexture.getTexture(), nullptr, &destrect);
}

/*void Text::render(const Area &src, const Area &dest) const {
	render(src, dest, DEFAULT_ANGLE, SDL_FLIP_NONE);
}

void Text::render(const Area &src, const Area &dest, float angle, const SDL_RendererFlip &flipType) const {
    SDL_Rect srcrect = {src.getX(), src.getY(), 
                        src.getWidth(), src.getHeight()};
    SDL_Rect destrect = {dest.getX(), dest.getY(), 
                         dest.getWidth(), dest.getHeight()};
    sdlRenderer.renderCopyEx(sdlTexture.getTexture(), &srcrect, &destrect, angle, flipType);
}*/
