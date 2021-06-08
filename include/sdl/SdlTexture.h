#ifndef _SDL_TEXTURE_H_
#define _SDL_TEXTURE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <cstdint>

class SDL_Texture;
class SdlRenderer;
class SDL_Surface;

struct Color {
    uint8_t r, g, b;
};

class SdlTexture {
    private:
        SDL_Texture *texture;

        void destroyTexture();
        void setColorKey(SDL_Surface* surface, int flag, Color key);

    public:
        SdlTexture(const std::string &imgPath, SdlRenderer &renderer);
        SdlTexture(const std::string &imgPath, SdlRenderer &renderer, Color key);
        SdlTexture(const std::string &imgPath, SdlRenderer &renderer,
                   Color key, SDL_BlendMode blending, uint8_t alpha);
        ~SdlTexture();
        void setTextureBlendMode(SDL_BlendMode blending);
        void setTextureAlphaMod(uint8_t alpha);
        SDL_Texture* getTexture() const;
};

#endif // _SDL_TEXTURE_H_
