#include "SdlTexture.h"
#include "SdlSurface.h"
#include "SdlRenderer.h"
#include "SdlException.h"

SdlTexture::SdlTexture(const char *imgPath, SdlRenderer &renderer) {
    SdlSurface surface(imgPath);
    texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), surface.getSurface());
    if (texture == nullptr) {
        throw SdlException("Error creando la textura. SDL_Error:");
    }
}

SdlTexture::SdlTexture(const char *imgPath, SdlRenderer &renderer, Color key) {
    SdlSurface surface(imgPath);
    setColorKey(surface.getSurface(), SDL_TRUE, key);
    texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), surface.getSurface());
    if (texture == nullptr) {
        throw SdlException("Error creando la textura. SDL_Error:");
    }
}

SdlTexture::SdlTexture(const char *imgPath, SdlRenderer &renderer,
                       Color key, SDL_BlendMode blending, uint8_t alpha)
    : SdlTexture(imgPath, renderer, key) {
    setTextureBlendMode(blending);
    setTextureAlphaMod(alpha);
}

SdlTexture::SdlTexture(SdlTexture &&other) : texture(other.texture) {
    other.texture = nullptr;
}

void SdlTexture::destroyTexture() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
}

SdlTexture::~SdlTexture() {
    destroyTexture();
}

SdlTexture& SdlTexture::operator=(SdlTexture &&other) {
    if (this == &other) return *this;
    destroyTexture();
    texture = other.texture;
    other.texture = nullptr;
    return *this;
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
    int errCode = SDL_SetColorKey(surface, flag, SDL_MapRGB(surface->format, key.red, key.green, key.blue)); 
    if (errCode < 0) {
        throw SdlException("Textura no pudo establecer el key color. SDL_Error:");
    }
}

SDL_Texture* SdlTexture::getTexture() const {
    return texture;
}
