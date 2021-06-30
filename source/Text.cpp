#include "Text.h"
#include "SdlRenderer.h"
#include "Window.h"
#include "Area.h"
#include <utility>
#include <iostream>

Text::Text(const char *fontPath, int ptsize,
		   const char *textToRender, 
		   SDL_Color color, 
		   Window &window) 
	: sdlFont(fontPath, ptsize),
	  sdlTexture(textToRender, color, window.getRenderer(), sdlFont),
	  sdlRenderer(window.getRenderer()),
	  posX(-1),posY(-1),width(-1),height(-1) { }

Text::Text(Text &&other) 
	: sdlFont(std::move(other.sdlFont)),
	  sdlTexture(std::move(other.sdlTexture)),
	  sdlRenderer(other.sdlRenderer) { }

Text::~Text() {
}

void Text::render(const Area &dest){
	posX = dest.getX();
	posY = dest.getY();
	width = dest.getWidth();
	height = dest.getHeight();

	SDL_Rect destrect = {dest.getX(), dest.getY(), 
                         dest.getWidth(), dest.getHeight()};
	sdlRenderer.renderCopy(sdlTexture.getTexture(), nullptr, &destrect);
}

bool Text::mouseInText(int x , int y){
	if ( (x > posX && x < (posX + width)) && 
		 (y > posY && y < (posY + height)) )
		return true;

	return false;
}

void Text::changeColor(int r, int g, int b){
	sdlTexture.changeColor(r,g,b);
}
