#include "SdlSurface.h"
#include "SdlException.h"
#include "SdlImageException.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

SdlSurface::SdlSurface(const char *pathImg) {
	surface = IMG_Load(pathImg);
	if (surface == nullptr) {
		throw SdlImageException("Error al cargar la imagen. SDL_Error:");
	}
}

SdlSurface::SdlSurface(int width, int height) {
	surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
	if (surface == nullptr) {
		throw SdlException("Error creando la superficie. SDL_Error:");
	}
}

SdlSurface::SdlSurface(SdlSurface &&other) : surface(other.surface) {
	other.surface = nullptr;
}

void SdlSurface::destroySurface() {
	if (surface != nullptr) {
		SDL_FreeSurface(surface);
	}
}

SdlSurface::~SdlSurface() {
	destroySurface();
}

SdlSurface& SdlSurface::operator=(SdlSurface &&other) {
	if (this == &other) return *this;
	destroySurface();
	surface = other.surface;
	other.surface = nullptr;
	return *this;
}

void SdlSurface::setColorKey(Color key) {
    int errCode = SDL_SetColorKey(surface, 
    							  SDL_TRUE, 
    							  SDL_MapRGB(surface->format, 
    							  			 key.red, 
    							  			 key.green, 
    							  			 key.blue)); 
    if (errCode < 0) {
        throw SdlException("Textura no pudo establecer el key color. SDL_Error:");
    }
}

SDL_Surface* SdlSurface::getSurface() const {
	return surface;
}
