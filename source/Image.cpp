#include "Image.h"
#include "SdlRenderer.h"
#include "Window.h"
#include "Area.h"
#include <utility>
#include <iostream>

#define DEFAULT_ANGLE 0

Image::Image(const char *pathImg, Window &window) 
	: sdlTexture(pathImg, window.getRenderer()), 
	  sdlRenderer(window.getRenderer()),path(pathImg) { }

Image::Image(Image &&other) 
    : sdlTexture(std::move(other.sdlTexture)), sdlRenderer(other.sdlRenderer) { }

Image::~Image() { }


Image& Image::operator=(Image &&other) {
    if (this == &other) return *this;
    sdlTexture = std::move(other.sdlTexture);
    sdlRenderer = std::move(other.sdlRenderer);
    return *this;
}

void Image::render(const Area &dest) const {
	SDL_Rect destrect = {dest.getX(), dest.getY(), 
                         dest.getWidth(), dest.getHeight()};
	sdlRenderer.renderCopy(sdlTexture.getTexture(), nullptr, &destrect);   
}

void Image::render(const Area &src, const Area &dest) const {
	render(src, dest, DEFAULT_ANGLE, SDL_FLIP_NONE);
}

void Image::render(const Area &src, const Area &dest, float angle, const SDL_RendererFlip &flipType) const {
    SDL_Rect srcrect = {src.getX(), src.getY(), 
                        src.getWidth(), src.getHeight()};
    SDL_Rect destrect = {dest.getX(), dest.getY(), 
                         dest.getWidth(), dest.getHeight()};
    sdlRenderer.renderCopyEx(sdlTexture.getTexture(), &srcrect, &destrect, angle, flipType);
}

void Image::render(int x, int y, const Area &dest) const {
    SDL_Rect srcrect = {0, 0, 
                        sdlTexture.getWidth(), sdlTexture.getHeight()};
    SDL_Rect destrect = {x, y, 
                         dest.getWidth(), dest.getHeight()};

    sdlRenderer.renderCopyEx( sdlTexture.getTexture(), &srcrect, &destrect, 0, SDL_FLIP_NONE);
}

const SdlTexture* Image::getTexture() const {
    return &sdlTexture;
}

int Image::getWidth() const{
    return sdlTexture.getWidth();
}

int Image::getHeight() const{
    return sdlTexture.getHeight();
}

const char* Image::getPath() const{
    return path;
}
