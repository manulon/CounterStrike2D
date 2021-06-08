#include "Image.h"
#include "SdlTexture.h"
#include "SdlRenderer.h"
#include "Window.h"
#include "Area.h"
#include <utility>

#define DEFAULT_ANGLE 0

Image::Image(const char *pathImg, Window &window) 
	: sdlTexture(pathImg, window.getRenderer()), 
	  sdlRenderer(window.getRenderer()) { }

Image::Image(Image &&other) 
    : sdlTexture(std::move(other.sdlTexture)), sdlRenderer(other.sdlRenderer) { }

Image::~Image() { }

void Image::render(const Area &src, const Area &dest, float angle, const SDL_RendererFlip &flipType) {
    SDL_Rect srcrect = {src.getX(), src.getY(), 
                        src.getWidth(), src.getHeight()};
    SDL_Rect destrect = {dest.getX(), dest.getY(), 
                         dest.getWidth(), dest.getHeight()};
    sdlRenderer.renderCopyEx(sdlTexture.getTexture(), &srcrect, &destrect, angle, flipType);
}

void Image::render(const Area &src, const Area &dest, const SDL_RendererFlip &flipType) {
    render(src, dest, DEFAULT_ANGLE, flipType);
}
