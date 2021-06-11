#ifndef _SDL_RENDERER_H_
#define _SDL_RENDERER_H_

class SdlWindow;
#include <cstdint>
#include <SDL2/SDL.h>

class SdlRenderer {
    private:
        SDL_Renderer *renderer;

        SdlRenderer(const SdlRenderer &other) = delete;
        SdlRenderer& operator=(const SdlRenderer &other) = delete;
        void destroyRenderer();
    
    public:
        SdlRenderer(SdlWindow &window);
        SdlRenderer(SdlWindow &window, uint32_t flags);
        SdlRenderer(SdlWindow &window, int index, uint32_t flags);
        SdlRenderer(SdlRenderer &&other);
        ~SdlRenderer();
        SdlRenderer& operator=(SdlRenderer &&other);
        void setRendererDrawColor(uint8_t red, uint8_t green, uint8_t blue,  uint8_t alpha) const;
        void setRenderTarget(SDL_Texture *texture) const;
        void renderDrawPoint(int x, int y) const;
        void renderClear() const;
        void renderPresent() const;
        void renderCopy(SDL_Texture *texture, const SDL_Rect *srcrect,
                        const SDL_Rect *dstrect) const;
        void renderCopyEx(SDL_Texture *texture, const SDL_Rect *srcrect,
                          const SDL_Rect *dstrect, const double angle,
                          const SDL_RendererFlip &flipType) const;
        void renderReadPixels(const SDL_Rect *rect, uint32_t format, 
                              void *pixels, int pitch) const;
        SDL_Renderer* getRenderer() const;
};

#endif // _SDL_RENDERER_H_
