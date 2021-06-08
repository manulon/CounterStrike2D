#include "SdlTexture.h"
#include "SdlSurface.h"
#include "SdlRenderer.h"
#include "SdlException.h"

SdlTexture::SdlTexture(const std::string &imgPath, SdlRenderer &renderer) {
    SdlSurface surface(imgPath.c_str());
    texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), surface.getSurface());
    if (texture == nullptr) {
        throw SdlException("Error creaando la textura. SDL_Error:");
    }
}

SdlTexture::SdlTexture(const std::string &imgPath, SdlRenderer &renderer, Color key) {
    SdlSurface surface(imgPath.c_str());
    setColorKey(surface.getSurface(), SDL_TRUE, key);
    texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), surface.getSurface());
    if (texture == nullptr) {
        throw SdlException("Error creando la textura. SDL_Error:");
    }
}

SdlTexture::SdlTexture(const std::string &imgPath, SdlRenderer &renderer,
                       Color key, SDL_BlendMode blending, uint8_t alpha)
    : SdlTexture(imgPath, renderer, key) {
    setTextureBlendMode(blending);
    setTextureAlphaMod(alpha);
}

void SdlTexture::setTextureBlendMode(SDL_BlendMode blending) {
    int errCode = SDL_SetTextureBlendMode(texture, blending);
    if (errCode < 0) {
        throw SdlException("Textura no pudo establecer el blend mode. SDL_Error:");
    }
}

void SdlTexture::setTextureAlphaMod(uint8_t alpha) {
    int errCode = SDL_SetTextureAlphaMod(texture, alpha);
    if (errCode < 0) {
        throw SdlException("Textura No pudo establecer el alpha mod. SDL_Error:");
    }
}

void SdlTexture::setColorKey(SDL_Surface* surface, int flag, Color key) {
    int errCode = SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, key.r, key.g, key.b)); 
    if (errCode < 0) {
        throw SdlException("Textura no pudo establecer el key color. SDL_Error:");
    }
}

void SdlTexture::destroyTexture() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
}

SdlTexture::~SdlTexture() {
    destroyTexture();
}

SDL_Texture* SdlTexture::getTexture() const {
    return texture;
}
