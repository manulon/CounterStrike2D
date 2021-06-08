#ifndef _SDL_TEXTURE_H_
#define _SDL_TEXTURE_H_

#include <SDL2/SDL.h>
#include <cstdint>

class SDL_Texture;
class SDL_Surface;
class SdlRenderer;

struct Color {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

class SdlTexture {
    private:
        SDL_Texture *texture;

        void destroyTexture();
        void setColorKey(SDL_Surface* surface, int flag, Color key);

    public:
        SdlTexture(const char *imgPath, SdlRenderer &renderer);
        SdlTexture(const char *imgPath, SdlRenderer &renderer, Color key);
        SdlTexture(const char *imgPath, SdlRenderer &renderer,
                   Color key, SDL_BlendMode blending, uint8_t alpha);
        SdlTexture(SdlTexture &&other);
        ~SdlTexture();
        SdlTexture& operator=(SdlTexture &&other);
        void setTextureBlendMode(SDL_BlendMode blending);
        void setTextureAlphaMod(uint8_t alpha);
        SDL_Texture* getTexture() const;
};

#endif // _SDL_TEXTURE_H_
