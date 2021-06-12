#include "Stencil.h"
#include "Window.h"
#include "Area.h"
#include "SdlRenderer.h"
#include "SdlSurface.h"
#include <cmath>
#include <iostream>

#define PI 3.14159265

Stencil::Stencil(int width, int height, 
				 int viewR, int viewAngle, uint8_t alpha,
				 Window &window) 
	: sdlTexture(window.getRenderer(), width, height),
	  sdlRenderer(window.getRenderer()),
	  width(width), height(height) { 
	drawStencil(0, 0, viewR, viewAngle);
	convertTexture();
	sdlTexture.setTextureAlphaBlend(SDL_BLENDMODE_BLEND, alpha);
}

Stencil::Stencil(Stencil &&other) 
	: sdlTexture(std::move(other.sdlTexture)), 
	  sdlRenderer(other.sdlRenderer) { }

Stencil::~Stencil() { }

void Stencil::convertTexture() {
	int width = 0;
	int height = 0;
	sdlTexture.queryTexture(nullptr, nullptr, &width, &height);
	SdlSurface surface(width, height);
	sdlRenderer.setRenderTarget(sdlTexture.getTexture());
	sdlRenderer.renderReadPixels(nullptr, 
								 surface.getSurface()->format->format, 
								 surface.getSurface()->pixels,
								 surface.getSurface()->pitch);
	sdlRenderer.setRenderTarget(nullptr);
	Color key = {0xFF, 0xFF, 0xFF};
	sdlTexture = SdlTexture(surface, sdlRenderer, key);
}

void Stencil::drawStencil(int Xc, int Yc, int viewR, float viewAngle) {
	sdlRenderer.setRenderTarget(sdlTexture.getTexture());
	clear();
	drawCircle(Xc, Yc, viewR);
	drawViewAngle(viewAngle);
	sdlRenderer.setRenderTarget(nullptr);
}

void Stencil::clear() {
	sdlRenderer.setRendererDrawColor(0x00, 0x00, 0x00, 0xFF);
	sdlRenderer.renderClear();
}

void Stencil::drawCircle(int Xc, int Yc, int r) {
	sdlRenderer.setRendererDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
	for (int x = 0; x <= r; x++) {
		for (int y = 0; y <= r; y++) {
			if (pow((x - Xc), 2) + pow((y - Yc), 2) <= pow(r,2)) {
				sdlRenderer.renderDrawPoint(x + (width/2), y + (height/2));
				sdlRenderer.renderDrawPoint((x * (-1)) + (width/2), y + (height/2));
				sdlRenderer.renderDrawPoint(x + (width/2), (y * (-1)) + (height/2));
				sdlRenderer.renderDrawPoint((x * (-1)) + (width/2), (y * (-1)) + (height/2));
			}
		}
	}
}

// Trabaja con maximo 180 grados de vision 
// TODO Aumentar la capacidad a mas de 180 grados.
void Stencil::drawViewAngle(int viewAngle) {
	double radians = ((viewAngle/2 * PI) / 180.0);
	sdlRenderer.setRendererDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
	for (int x = 0; x <= (width/2); x++) {
		for (int y = 0; y <= (height/2); y++) {
			if (y <= (tan(radians)) * x) {
				sdlRenderer.renderDrawPoint(x + (width/2), y * (-1) + (height/2));
				sdlRenderer.renderDrawPoint(x + (width/2), y + (height/2));
			} else {
					break;
			}
		}
	}
}

void Stencil::render(const Area &dest, const double angle) const {
    SDL_Rect destrect = {dest.getX(), dest.getY(), 
                         dest.getWidth(), dest.getHeight()};
	sdlRenderer.renderCopyEx(sdlTexture.getTexture(), nullptr, &destrect, angle, SDL_FLIP_NONE);
}
