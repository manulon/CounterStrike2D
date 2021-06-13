#include "SdlTexture.h"
#include "SdlRenderer.h"
#include "SdlException.h"

SdlTexture::SdlTexture(const char *imgPath, const SdlRenderer &renderer) {
    SdlSurface surface(imgPath);
    texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), surface.getSurface());
    if (texture == nullptr) {
        throw SdlException("Error creando la textura. SDL_Error:");
    }
}

SdlTexture::SdlTexture(const char *text, SDL_Color textColor, 
                       const SdlRenderer &renderer,
                       const SdlFont &font) {
    SdlSurface surface(text, textColor, font);
    texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), surface.getSurface());
    if (texture == nullptr) {
        throw SdlException("Error creando la textura. SDL_Error:");
    }    
}

SdlTexture::SdlTexture(const SdlRenderer &renderer, int width, int height) { 
    texture = SDL_CreateTexture(renderer.getRenderer(), SDL_PIXELFORMAT_RGBA8888, 
                                SDL_TEXTUREACCESS_TARGET, width, height);
    if (texture == nullptr) {
        throw SdlException("Error creando la textura. SDL_Error:");
    }
}

SdlTexture::SdlTexture(SdlSurface &surface, const SdlRenderer &renderer, Color key) {
    surface.setColorKey(key);
    texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), surface.getSurface());
    if (texture == nullptr) {
        throw SdlException("Error creando la textura. SDL_Error:");
    }
}

SdlTexture::SdlTexture(const char *imgPath, const SdlRenderer &renderer, Color key) {
    SdlSurface surface(imgPath);
    surface.setColorKey(key);
    texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), surface.getSurface());
    if (texture == nullptr) {
        throw SdlException("Error creando la textura. SDL_Error:");
    }
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

void SdlTexture::setTextureAlphaBlend(SDL_BlendMode blending, uint8_t alpha) {
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

void SdlTexture::queryTexture(uint32_t *format, int *access, int *w, int *h) {
    int errCode = SDL_QueryTexture(texture, format, access, w, h);
    if (errCode < 0) {
        throw SdlException("Fallo la consulta a la textura. SDL_Error:");
    }
}

SDL_Texture* SdlTexture::getTexture() const {
    return texture;
}
