#ifndef _SDL_RENDERER_H_
#define _SDL_RENDERER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class SDL_Renderer;
class SDL_Texture;
class SdlWindow;
#include <cstdint>

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
        void setRendererDrawColor(uint8_t red, uint8_t green, uint8_t blue,  uint8_t alpha);
        void renderClear();
        void renderPresent();
        void renderCopyEx(SDL_Texture *texture, const SDL_Rect *srcrect,
                               const SDL_Rect *dstrect, const double angle,
                               const SDL_RendererFlip &flipType);
        SDL_Renderer* getRenderer() const;
};

#endif // _SDL_RENDERER_H_
