#include "SdlRenderer.h"
#include "SdlWindow.h"
#include "SdlException.h"

#define INDEX_FLAGS -1

SdlRenderer::SdlRenderer(){}

SdlRenderer::SdlRenderer(SdlWindow &window) 
    : SdlRenderer(window, INDEX_FLAGS, SDL_RENDERER_ACCELERATED) { }

SdlRenderer::SdlRenderer(SdlWindow &window, uint32_t flags)
    : SdlRenderer(window, INDEX_FLAGS, flags) { }

SdlRenderer::SdlRenderer(SdlWindow &window, int index, uint32_t flags) 
    : renderer(nullptr) {
    renderer =  SDL_CreateRenderer(window.getWindow(), index, flags);
    if (renderer == nullptr) {
        throw SdlException("SdlRenderer no se pudo crear. SDL_Error:");
    }
}

SdlRenderer::SdlRenderer(SdlRenderer &&other) : renderer(other.renderer) {
    other.renderer = nullptr;
}

void SdlRenderer::destroyRenderer() {
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
}

SdlRenderer::~SdlRenderer() {
    destroyRenderer();
}

SdlRenderer& SdlRenderer::operator=(SdlRenderer &&other) {
    if (this == &other) return *this;
    destroyRenderer();
    renderer = other.renderer;
    other.renderer = nullptr;
    return *this;
}

void SdlRenderer::setRendererDrawColor(uint8_t red, uint8_t green, uint8_t blue,  uint8_t alpha) const {
    int errCode = SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
    if (errCode < 0){
        throw SdlException("SdlRenderer no pudo renderizar el color para dibujar. SDL_Error:");
    }
}

void SdlRenderer::setRenderTarget(SDL_Texture *texture) const {
    int errCode = SDL_SetRenderTarget(renderer,
                                      texture);
    if (errCode < 0){
        throw SdlException("SdlRenderer no pudo establecer de target a la textura. SDL_Error:");
    }   
}

void SdlRenderer::renderDrawPoint(int x, int y) const {
    int errCode = SDL_RenderDrawPoint(renderer, x, y);
    if (errCode < 0){
        throw SdlException("SdlRenderer no pudo establecer renderizar el punto. SDL_Error:");
    }    
}

void SdlRenderer::renderClear() const {
    int errCode = SDL_RenderClear(renderer);
    if (errCode < 0) {
        throw SdlException("SdlRender no pudo limpiar el renderizado con el color establecido. SDL_Error:");
    }
}

void SdlRenderer::renderPresent() const {
    SDL_RenderPresent(renderer);
}

void SdlRenderer::renderCopyEx(SDL_Texture *texture,const  SDL_Rect *srcrect,
                               const SDL_Rect *dstrect, const double angle,
                               const SDL_RendererFlip& flipType) const{
    int errCode = SDL_RenderCopyEx(renderer, texture, 
                                   srcrect, dstrect, angle, nullptr, flipType);
    if (errCode < 0) {
        throw SdlException("SdlRender no pudo renderizar la textura. SDL_Error:");
    }
}

void SdlRenderer::renderCopy(SDL_Texture *texture, const SDL_Rect *srcrect,
                             const SDL_Rect *dstrect) const {
    int errCode = SDL_RenderCopy(renderer, texture, srcrect, dstrect);
    if (errCode < 0) {
        throw SdlException("SdlRender no pudo renderizar la textura. SDL_Error:");
    }
}

void SdlRenderer::renderReadPixels(const SDL_Rect *rect, uint32_t format, 
                                   void *pixels, int pitch) const {
    int errCode = SDL_RenderReadPixels(renderer, rect, format, pixels, pitch);
    if (errCode < 0) {
        throw SdlException("SdlRenderer no pudo copiar los pixels del renderizado. SDL_Error:");
    }
}

SDL_Renderer* SdlRenderer::getRenderer() const {
    return renderer;
}
