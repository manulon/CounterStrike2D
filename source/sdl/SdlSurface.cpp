#include "SdlSurface.h"
#include "SdlException.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

SdlSurface::SdlSurface(const char *pathImg) {
	surface = IMG_Load(pathImg);
	if (surface == nullptr) {
		throw SdlException("Error al cargar la imagen. SDL_Error:");
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

SDL_Surface* SdlSurface::getSurface() const {
	return surface;
}
