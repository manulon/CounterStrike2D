#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SdlTexture.h"
class Area;
class SdlRenderer;
class Window;

class Image {
    private:
        SdlTexture sdlTexture;
        SdlRenderer &sdlRenderer;

        Image(const Image &other) = delete;
        Image& operator=(const Image &other) = delete;
    
    public:
        Image(const char *pathImg, Window &window);
        //Image(Image &&other);
        ~Image();
        //Image& operator=(Image &&other);
        void render(const Area& src, const Area& dest, float angle, const SDL_RendererFlip& flipType);
        void render(const Area& src, const Area& dest, const SDL_RendererFlip& flipType);
};

#endif // _IMAGE_H_
