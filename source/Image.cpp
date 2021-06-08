#include "Image.h"
#include "SdlTexture.h"
#include "SdlRenderer.h"
#include "Window.h"
#include "Area.h"

Image::Image(const char *pathImg, Window &window) 
	: sdlTexture(pathImg, window.getRenderer()), 
	  sdlRenderer(window.getRenderer()) { }

Image::~Image() { }

void Image::render(const Area& src, const Area& dest, float angle, const SDL_RendererFlip& flipType) {
    SDL_Rect sdlSrc = {
            src.getX(), src.getY(),
            src.getWidth(), src.getHeight()
    };
    SDL_Rect sdlDest = {
            dest.getX(), dest.getY(),
            dest.getWidth(), dest.getHeight()
    };
    sdlRenderer.renderCopyEx(sdlTexture.getTexture(), &sdlSrc, &sdlDest, angle, flipType);
}

void Image::render(const Area& src, const Area& dest, const SDL_RendererFlip& flipType) {
    render(src, dest, 0, flipType);
}
