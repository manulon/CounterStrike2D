#ifndef _SDL_TEXTURE_H_
#define _SDL_TEXTURE_H_

#include "SdlSurface.h"
#include "Area.h"
#include <SDL2/SDL.h>
#include <cstdint>

class SDL_Texture;
class SDL_Surface;
class SdlRenderer;
class SdlSurface;

class SdlTexture {
    private:
        SDL_Texture *texture;

        void destroyTexture();
        SdlTexture(const SdlTexture &other) = delete;
        SdlTexture operator=(SdlTexture &other) = delete;
        void setTextureBlendMode(SDL_BlendMode blending);
        void setTextureAlphaMod(uint8_t alpha);

    public:
        SdlTexture();
        SdlTexture(const char *imgPath, const SdlRenderer &renderer);
        SdlTexture(const char *text, SDL_Color textColor, 
                   const SdlRenderer &renderer,
                   const SdlFont &font);
        SdlTexture(const SdlRenderer &renderer, int width, int height);
        SdlTexture(SdlSurface &surface, const SdlRenderer &renderer, Color key);
        SdlTexture(const char *imgPath, const SdlRenderer &renderer, Color key);
        SdlTexture(SdlTexture &&other);
        ~SdlTexture();
        SdlTexture& operator=(SdlTexture &&other);
        void queryTexture(uint32_t *format, int *access, int *w, int *h) const;
        void setTextureAlphaBlend(SDL_BlendMode blending, uint8_t alpha);
        SDL_Texture* getTexture() const;
        int getWidth() const;
        int getHeight() const;
        void changeColor(int r, int g, int b);
};

#endif // _SDL_TEXTURE_H_
