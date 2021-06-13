#include "Text.h"
#include "SdlRenderer.h"
#include "Window.h"
#include "Area.h"
#include <utility>

Text::Text(const char *fontPath, int ptsize,
		   const char *textToRender, 
		   SDL_Color color, 
		   Window &window) 
	: sdlFont(fontPath, ptsize),
	  sdlTexture(textToRender, color, window.getRenderer(), sdlFont),
	  sdlRenderer(window.getRenderer()) { }

Text::Text(Text &&other) 
	: sdlFont(std::move(other.sdlFont)),
	  sdlTexture(std::move(other.sdlTexture)),
	  sdlRenderer(other.sdlRenderer) { }

Text::~Text() { }

void Text::render(const Area &dest) const {
	SDL_Rect destrect = {dest.getX(), dest.getY(), 
                         dest.getWidth(), dest.getHeight()};
	sdlRenderer.renderCopy(sdlTexture.getTexture(), nullptr, &destrect);
}
